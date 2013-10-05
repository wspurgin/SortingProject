/*
Nastasha Gerlt, Will Spurgin
9/13/2013
Data Structures -- Sorting Competition
"Word" class header file
*/

#ifndef WORD_H
#define WORD_H

#include <cstring>
#include <iostream>

using namespace std;

class Word
{
private:
	char* string_;
	int string_length_; //including the null terminator, total space allocated.

	void resize(char* string);
	void resize(const char* string);

public:
	//Constructor-Default
	Word();

	//Constructor-const char*
	Word(const char* string);

	//Constructor-char*
	Word(char* string);

	//Constructor-Copy
	Word(const Word& rhs);

	//Destructor
	~Word();

	//Accessors
	char* getString() const;

	int len() const; 

	//Operator Overloads (comparison operators will be overwritten for both
	//Words and char*)
	bool operator==(const Word& rhs);

	bool operator==(const char* rhs);

	Word& operator=(const Word& rhs);

	Word& operator=(const char* rhs);

	bool operator<(const Word& rhs);

	bool operator<(const char* rhs);

	bool operator>(const Word& rhs);

	bool operator>(const char* rhs);

	Word& operator+=(const Word& rhs);

	Word operator+(const Word& rhs);

	//friend operator overloads

	friend ostream& operator<<(ostream& out, Word& rhs);

	friend istream& operator>>(istream& in, Word& rhs);

	friend bool operator==(const char* string, Word& rhs);

	friend bool operator==(char* string, Word& rhs);

	friend bool operator<(const char* string, Word& rhs);

	friend bool operator<(char* string, Word& rhs);

	friend bool operator>(const char* string, Word& rhs);

	friend bool operator>(char* string, Word& rhs);
};

#endif