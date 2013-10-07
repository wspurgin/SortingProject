/*
Nastasha Gerlt, Will Spurgin
9/13/2013
Data Structures -- Sorting Competition
"Word" class implementation file
*/

#include "Word.h"

using namespace std;

Word::Word()
{
	this->string_ = NULL;
	this->string_length_ = 0;
}

Word::Word(const char* string)
{

	this->string_length_ = strlen(string) + 1;
	this->string_ = new char[this->string_length_];
	strcpy(this->string_, string);
}

Word::Word(char* string)
{

	this->string_length_ = strlen(string) + 1;
	this->string_ = new char[this->string_length_];
	strcpy(this->string_, string);
}

Word::Word(const Word& rhs)
{
	this->string_length_ = 0;
	resize(rhs.getString());	
}

Word::~Word()
{
	if(this->string_length_ != 0)
		delete [] string_;
}

void Word::resize(char* string)
{
	if(this->string_length_ != 0)
		delete [] string_;
	this->string_length_ = strlen(string) + 1;
	this->string_ = new char[this->string_length_];
	strcpy(this->string_, string);
}

void Word::resize(const char* string)
{
	if(this->string_length_ != 0)
		delete [] string_;
	this->string_length_ = strlen(string) + 1;
	this->string_ = new char[this->string_length_];
	strcpy(this->string_, string);
}

char* Word::getString() const
{
	return this->string_;
}

int Word::len() const
{
	return this->string_length_;
}

bool Word::operator==(const Word& rhs)
{
	if(strcmp(this->string_, rhs.getString()) == 0)
		return true;
	return false;
}

bool Word::operator==(const char* rhs)
{
	if(strcmp(this->string_, rhs) == 0)
		return true;
	return false;
}

Word& Word::operator=(const Word& rhs)
{
	resize(rhs.getString());
	return *this;
}

Word& Word::operator=(const char* rhs)
{
	resize(rhs);
	return *this;
}

bool Word::operator<(const Word& rhs)
{
	if(strcmp(this->string_, rhs.getString()) > 0)
		return true;
	return false;
}

bool Word::operator<(const char* rhs)
{
	if(strcmp(this->string_, rhs) > 0)
		return true;
	return false;
}


bool Word::operator>(const Word& rhs)
{
	// return !(this < rhs)
	if(strcmp(this->string_, rhs.getString()) < 0)
		return true;
	return false;
}

bool Word::operator>(const char* rhs)
{
	if(strcmp(this->string_, rhs) < 0)
		return true;
	return false;
}

Word& Word::operator+=(const Word& rhs)
{
	char* temp = new char[this->string_length_];
	strcpy(temp, this->string_);
	/* Delete the current contents of string_, but if the length
	is equal to zero. Set the lenth equal to 1 to avoid errors in the 
	allocation statement.
	*/
	if(this->string_length_ != 0)
		delete [] this->string_;
	else
		this->string_length_ = 1;
	/*The allocated space of the new string will be the old string length
	plus the the len() of rhs - 1 (because there will be only one null 
	terminator, not two).
	*/
	this->string_length_+= rhs.len() - 1;
	this->string_ = new char[this->string_length_];
	strcpy(this->string_, temp);
	strcat(this->string_, rhs.getString());
	delete [] temp;

	return *this;
}

Word Word::operator+(const Word& rhs)
{
	char* temp = new char[this->string_length_ + rhs.len() - 1];
	strcpy(temp, this->string_);
	strcat(temp, rhs.getString());
	Word sum(temp);
	delete [] temp;
	return sum;
}

ostream& operator<<(ostream& out, Word& rhs)
{
	out << rhs.string_;
	return out;
}

istream& operator>>(istream& in, Word& rhs)
{
	if(rhs.string_length_ != 0)
		delete [] rhs.string_;
	rhs.string_length_ = 2;
	char* temp;
	char c = in.peek();
	//ignore whitespace
	while(c == ' ' || c == '\n' || c == '\r')
	{
		if(c == ' ')
			in.ignore(256, ' ');
		else if(c == '\n')
			in.ignore(256, '\n');
		else if(c == '\r')
			in.ignore(256, '\r');
		c = in.peek();
	}
	//Now read in each character until next white space

	//Priming read
	rhs.string_ = new char[rhs.string_length_];
	in.get(rhs.string_, 2);
	c = in.peek();
	//Read the rest of the characters
	while(c != ' ' && c != '\n' && '\r' && in.good())
	{
		char* temp2 = new char[2];
		in.get(temp2, 2);
		temp = new char[rhs.string_length_];
		strcpy(temp, rhs.string_);
		
		//delete what is currently stored in string_
		delete [] rhs.string_;
		//increment for the added character
		rhs.string_length_++;

		rhs.string_ = new char[rhs.string_length_];
		strcpy(rhs.string_, temp);
		strcat(rhs.string_, temp2);

		//clean up memory
		delete [] temp;
		delete [] temp2;

		c = in.peek();
	}
	return in;
}

// Non member operator overloads so a Word won't always have to be lhs.

bool operator==(const char* string, Word& rhs)
{
	if(strcmp(string, rhs.string_) == 0)
		return true;
	return false;
}

bool operator<(const char* string, Word& rhs)
{
	if(strcmp(string, rhs.string_) < 0)
		return true;
	return false;
}

bool operator>(const char* string, Word& rhs)
{
	if(strcmp(string, rhs.string_) > 0)
		return true;
	return false;
}

bool operator==(char* string, Word& rhs)
{
	if(strcmp(string, rhs.string_) == 0)
		return true;
	return false;
}

bool operator<(char* string, Word& rhs)
{
	if(strcmp(string, rhs.string_) < 0)
		return true;
	return false;
}

bool operator>(char* string, Word& rhs)
{
	if(strcmp(string, rhs.string_) > 0)
		return true;
	return false;
}
