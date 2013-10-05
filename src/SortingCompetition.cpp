/*
Nastasha Gerlt, Will Spurgin
10/04/2013
Project 3 - Sorting Competition
cpp file for "SortingCompetition" class
*/

#include <string>
#include "Word.h"


SortingCompetition::SortingCompetition(const string& inputFileName)
{
	this->words = NULL;
	this->copy = NULL;
	this->wordsSize = 0;
	this->copySize = 0;
	this->inputFile = inputFileName;
}

SortingCompetition::~SortingCompetition()
{
	if(wordsSize > 0)
		delete [] words;
	if(copySize > 0)
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

void write(ostream& out)
{
	out << "Sorted Word Index:" << endl << endl;
	for(int i = 0; i < this->copySize; i++)
		out << this->copy[i] << endl;
	out << endl << endl << "######## END OF INDEX ########" << endl;
}

void SortingCompetition::setFileName(const string& inputFileName)
{
	this->inputFile = inputFileName;
}


bool SortingCompetition::readData()
{
	fstream fin(this->inputFile);
	if(fin)
	{
		if(this->wordsSize > 0)
			delete [] wordsSize;

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
				resize(this->words, this->wordsSize + 1, this->wordsSize);
				this->wordsSize++;
			}
			this->words[i] = buffer;
		}
		return true;	
	}
	else
	{
		cout << "ERROR: FILE NOT FOUND '" << this->inputFile << "'" << endl;
		return false;
	}	
}

bool SortingCompetition::prepareData()
{

}


void SortingCompetition::sortData()
{
	selectionSort(this->copy, this->copySize);
}


void SortingCompetition::outputData(const string& outputFileName)
{
	if(outputFileName == "stdout")
		write(cout);
	else
	{
		fstream fout(outputFileName);
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
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			else if(arr[i].len() == arr[j].len() && arr[i] < arr[j])
			{
				//swap two words in an array
				Word temp = arr[i];
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


