/*
Nastasha Gerlt, Will Spurgin
10/04/2013
Project 3 - Sorting Competition
Implementation file for "SortingCompetition" class
*/

#include <string>
#include <time.h>
#include <stdlib.h>
#include "Word.h"
#include "SortingCompetition.h"


SortingCompetition::SortingCompetition(const string& inputFileName)
{
	this->words = NULL;
	this->copy = NULL;
	this->wordsSize = 0;
	this->copySize = 0;
	this->copyCapacity = 0;
	this->inputFile = inputFileName;
}

SortingCompetition::~SortingCompetition()
{
	if(wordsSize > 0)
		delete [] words;
	if(copyCapacity > 0)
		delete [] copy;
}

void SortingCompetition::resize(Word*& words, int cap, int size)
{
	Word* temp = words;
	words = new Word[cap];
	for(int i = 0; i < size; i++)
		words[i] = temp[i];
	if(size > 0)
		delete [] temp;
}

void SortingCompetition::write(ostream& out)
{
	out << "######## SORTED WORD INDEX ########" << endl << endl;
	for(int i = 0; i < this->copySize; i++)
		out << this->copy[i] << endl;
	out << endl << endl << "######## END OF INDEX ########" << endl;
}

int SortingCompetition::compare(Word& lhs, Word& rhs)
{
	if(lhs.len() > rhs.len())
		return 1;
	else if(lhs.len() < rhs.len())
		return -1;
	else if(lhs > rhs)
		return -1;
	else if(lhs < rhs)
		return 1;
	else
		return 0;
}

void SortingCompetition::swap(Word*& arr, int i, int j)
{
	Word temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void SortingCompetition::setFileName(const string& inputFileName)
{
	this->inputFile = inputFileName;
}


bool SortingCompetition::readData()
{
	fstream fin(this->inputFile.c_str());
	if(fin)
	{
		if(this->wordsSize > 0)
			delete [] words;

		this->wordsSize++;
		this->words = new Word[this->wordsSize];
		Word buffer;

		//priming read
		int i = 0;
		fin >> buffer;
		this->words[i] = buffer;
		i++;

		while(fin >> buffer)
		{
			if(i == this->wordsSize)
			{
				resize(this->words, this->wordsSize*2, this->wordsSize);
				this->wordsSize = this->wordsSize*2;
			}
				this->words[i] = buffer;
			i++;
		}
		//read the last entry in buffer into words
		this->copySize = i;
		if(i == this->wordsSize)
		{
			resize(this->words, this->wordsSize + 1, this->wordsSize);
			this->wordsSize++;
		}
		this->words[i] = buffer;
		this->copySize++;

		return true;
	}
	else
	{
		cerr << "ERROR: FILE NOT FOUND '" << this->inputFile << "'" << endl;
		return false;
	}	
}

bool SortingCompetition::prepareData()
{
	if(this->wordsSize <= 0)
	{
		cerr << "ERROR: No data found in index. Make sure to call"
		<< " readData() first." << endl;
		return false;
	}
	if(this->copyCapacity > 0)
		delete[] copy;
	this->copyCapacity = this->copySize;
	this->copy = new Word[copyCapacity];
	for(int i = 0; i < this->copySize; i++)
	{
		this->copy[i] = this->words[i];
	}
	return true;
}


void SortingCompetition::sortData()
{
	// selectionSort(this->copy, this->copySize);
	quickSort(this->copy, 0, this->copySize-1);
	// quickSort2(this->copy, 0, this->copySize-1);
}

	
void SortingCompetition::outputData(const string& outputFileName)
{
	if(outputFileName == "stdout")
		write(cout);
	else
	{
		fstream fout(outputFileName.c_str());
		write(fout);
		fout.close();
	}
}


Word* SortingCompetition::getWords()
{
	return this->words;
}


Word* SortingCompetition::getCopy()
{
	return this->copy;
}


int SortingCompetition::getWordsSize()
{
	return this->wordsSize;
}


int SortingCompetition::getCopySize()
{
	return this->copySize;
}


string SortingCompetition::getInputFileName()
{
	return this->inputFile;
}


void SortingCompetition::selectionSort(Word*& arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = i +1; j < size; j++)
		{
			if(arr[i].len() > arr[j].len())
			{
				//swap two words in an array
				Word temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			else if(arr[i].len() == arr[j].len() && arr[i] < arr[j])
			{
				//swap two words in an array
				Word temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void SortingCompetition::quickSort(Word*& arr, int start, int end)
{
	// srand(time(NULL));
	if(end - start < 1)
		return;
	// Word x = arr[start + rand()%(end-start)];
	int pivot = start / end;
	int i = start; 
	int j = end;
	while(i < j && i < pivot && j > pivot)
	{
		while(compare(arr[i], arr[pivot]) <= 0)
		{
			if(i >= j)
				break;
			i++;
		}
		while(compare(arr[j], arr[pivot]) >= 0)
		{
			if(j < i)
				break;
			j--;
		}
		if(i < j)
		{
			// swap(arr, i, j);
			Word temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	if(compare(arr[j], arr[pivot]) <= 0)
	{
		// swap(arr, pivot, j);
		Word temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
	}
	else if(compare(arr[i], arr[pivot]) <= 0)
	{
		// swap(arr, pivot, i);
		Word temp = arr[pivot];
		arr[pivot] = arr[i];
		arr[i] = temp;
	}
	quickSort(arr, start, j-1);
	quickSort(arr, j+1, end);
}		

void SortingCompetition::quickSort2(Word*& arr, int start, int end)
{
	if(end - start < 1)
		return;
	int pivot = end;
	int i = start;
	int j = end - 1;
	while(i < j)
	{
		if(compare(arr[i], arr[pivot]) > 0)
		{
			if(compare(arr[j], arr[pivot]) <= 0)
				swap(arr, i, j);
			else
				j--;
		}
		else
			i++;
	}
	if(compare(arr[i], arr[pivot]) > 0)
		swap(arr, i, pivot);
	quickSort2(arr, start, i-1);
	quickSort2(arr, i+1, end);
}