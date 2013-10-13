/*
Nastasha Gerlt, Will Spurgin
10/03/2013
Project 3 - Sorting Competition
Header file for "SortingCompetition" class
*/

#ifndef SORTING_COMPETITION_H
#define SORTING_COMPETITION_H

#include <string>
#include <fstream>
#include "Word.h"

class SortingCompetition
{
private:
	Word** words;
	Word** copy;
	string inputFile;
	int wordsSize;
	int copySize;
	int copyCapacity;

	void resize(Word**& words, int cap, int size);

	//write function
	void write(ostream& out);

	//custom compare function because of length requirement
	int compare(Word& lhs, Word& rhs);

	//swap arr[i] value with arr[j] value
	void swap(Word**& arr, int i, int j);

	

	void merge2(Word**& arr, int startA, int endA, int startB, int endB);

	//actual sorting algorithms are private, the public function 'sortData'
	//will call the algorithm(s) that will actually be used.
	void selectionSort(Word**& arr, int size);

	void heapSort(Word**& arr, int start, int end);

	void quickSort2(Word**& arr, int start, int end);

	void quickSort(Word**& arr, int start, int end);

	void insertionSort(Word**& arr, int start, int end);


public:
	//Basic constructor that accpets file input string 
	SortingCompetition(const string& inputFileName);

	~SortingCompetition();

	//Setter for Inputfile
	void setFileName(const string& inputFileName);

	//Read data from inputFile into words
	bool readData();

	//Copy the contents of words into copy
	bool prepareData();

	/*
	*Sort data (Sorting consists of checking first size and then the 
	*alphabetical sorting) so 'z' comes before 'all'.
	*NOTE this function calls the recursive sorting algorithm, it does not
	*actually hold any of the code specific for the sort.
	*/
	void sortData();

	//Output 'copy' to the file provided.
	void outputData(const string& outputFileName);

	//Getters
	Word** getWords();

	Word** getCopy();

	int getWordsSize();

	int getCopySize();

	string getInputFileName();
};
#endif
