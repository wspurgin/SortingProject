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
	if(this->wordsSize > 0)
	{
		for(int i = 0; i < this->wordsSize; i++)
			delete words[i];
		delete [] words;
	}
	if(copyCapacity > 0)
	{
		for(int i = 0; i < this->copyCapacity; i++)
			delete copy[i];
		delete [] copy;
	}
}

void SortingCompetition::resize(Word**& words, int cap, int size)
{
	Word** temp = words;
	words = new Word*[cap];
	for(int i = 0; i < size; i++)
		words[i] = temp[i];
	if(size > 0)
		delete [] temp;
}

void SortingCompetition::write(ostream& out)
{
	out << "######## SORTED WORD INDEX ########" << endl << endl;
	for(int i = 0; i < this->copySize; i++)
		out << *this->copy[i] << endl;
	out << endl << endl << "######## END OF INDEX ########" << endl;
}

int SortingCompetition::compare(Word& lhs, Word& rhs)
{
	if(lhs.len() > rhs.len())
		return 1;
	else if(lhs.len() < rhs.len())
		return -1;
	if(lhs > rhs)
		return -1;
	else if(lhs < rhs)
		return 1;
	else
		return 0;
}

void SortingCompetition::swap(Word**& arr, int i, int j)
{
	Word* temp = arr[i];
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
		this->words = new Word*[this->wordsSize];
		Word buffer;

		//priming read
		int i = 0;
		fin >> buffer;
		this->words[i] = new Word(buffer);
		i++;

		while(fin >> buffer)
		{
			if(i == this->wordsSize)
			{
				resize(this->words, this->wordsSize*2, this->wordsSize);
				this->wordsSize = this->wordsSize*2;
			}
				this->words[i] = new Word(buffer);
			i++;
		}
		//read the last entry in buffer into words
		this->copySize = i;
		if(i == this->wordsSize)
		{
			resize(this->words, this->wordsSize + 1, this->wordsSize);
			this->wordsSize++;
		}
		this->words[i] = new Word(buffer);
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
	if(copyCapacity > 0)
	{
		for(int i = 0; i < this->copyCapacity; i++)
			delete copy[i];
		delete [] copy;
	}
	this->copyCapacity = this->copySize;
	this->copy = new Word*[copyCapacity];
	for(int i = 0; i < this->copySize; i++)
	{
		this->copy[i] = new Word(*this->words[i]);
	}
	return true;
}


void SortingCompetition::sortData()
{
	// selectionSort(this->copy, this->copySize);
	// insertionSort(this->copy, 0, this->copySize-1);
	if(this->copyCapacity > 100000)
		quickSort(this->copy, 0, (this->copySize-1)/2);
	quickSort(this->copy, 0, this->copySize-1);
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


Word** SortingCompetition::getWords()
{
	return this->words;
}


Word** SortingCompetition::getCopy()
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


void SortingCompetition::selectionSort(Word**& arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = i +1; j < size; j++)
		{
			if(arr[i]->len() > arr[j]->len())
			{
				//swap two words in an array
				Word* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			else if(arr[i]->len() == arr[j]->len() && *arr[i] < *arr[j])
			{
				//swap two words in an array
				Word* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void SortingCompetition::quickSort(Word**& arr, int start, int end)
{	
	if(end - start < 1)
		return;
	int pivot = start;
	int i = pivot + 1; 
	int j = end;
	while(i < j)
	{
		while(compare(*arr[i], *arr[pivot]) <= 0)
		{
			if(i >= j)
				break;
			i++;
		}
		while(compare(*arr[j], *arr[pivot]) >= 0)
		{
			if(j < i)
				break;
			j--;
		}
		if(i < j)
			swap(arr, i, j);
	}

	if(compare(*arr[j], *arr[pivot]) <= 0)
		swap(arr, j, pivot);
	else if(compare(*arr[i], *arr[pivot]) <= 0)
		swap(arr, i, pivot);

	quickSort(arr, start, j-1);
	quickSort(arr, j+1, end);
}		

void SortingCompetition::quickSort2(Word**& arr, int start, int end)
{
	if(end - start < 1)
		return;
	int pivot = (start + end)/2;
	int i = start;
	int j = end;
	while(i < j)
	{
		if(compare(*arr[i], *arr[pivot]) > 0)
		{
			if(compare(*arr[j], *arr[pivot]) <= 0)
			{
				swap(arr, i, j);
				i++; j--;
			}
			else
				j--;
		}
		else
			i++;
	}
	if(compare(*arr[i], *arr[pivot]) > 0)
		swap(arr, i, pivot);
	quickSort2(arr, start, pivot-1);
	quickSort2(arr, pivot+1, end);
}


void SortingCompetition::heapSort(Word**& arr, int start, int end)
{
	//ummm I was just not sure what to do bc I wanted to snuggle...
}

void SortingCompetition::insertionSort(Word**& arr, int start, int end)
{
	for(int i = start + 1; i <= end; i++)
	{
		Word* val = arr[i];
		int hole = i;
		while(hole > 0 && compare(*val, *arr[hole - 1]) <= 0)
		{
			arr[hole] = arr[hole - 1];
			hole--;
		}
		arr[hole] = val;
	}
}

void SortingCompetition::merge(Word**& arr, int sizeA, Word**& brr, int sizeB)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (k != this->copySize && i <= sizeA && j <= sizeB)
	{
		if(comp(*arr[i], *brr[j]) <= 0)
		{
			this->copy[k] = *arr[i];
			i++;
		}
        else
		{
			this->copy[k] = *brr[j];
			j++;
		}
		k++;
	}
}






