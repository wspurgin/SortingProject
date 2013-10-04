/*
Nastasha Gerlt, Will Spurgin
10/04/2013
Project 3 - Sorting Competition
cpp file for "SortingCompetition" class
*/

#include <string>
#include "Word.h"


SortingCompetition:SortingCompetition(const string& inputFileName)
{
}


SortingCompetition::setFileName(const string& inputFileName)
{
	inputFile = inputFileName;
}


bool SortingCompetition::readData()
{
}

bool SortingCompetition::prepareData()
{
}


void SortingCompetition::sortData()
{
	/*
	*Sort data (Sorting consists of checking first size and then the 
	*alphabetical sorting) so 'z' comes before 'all'.
	*NOTE this function calls the recursive sorting algorithm, it does not
	*actually hold any of the code specific for the sort.
	*/
}


void SortingCompetition::outputData(const string& outputFileName)
{
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

