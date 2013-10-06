/*
Nastasha Gerlt, Will Spurgin
October 5, 2013
Data Structures -- Sorting Competition
Testing file
*/

#include "SortingCompetition.h"

using namespace std;

int main(int argc, char** argv)
{
	SortingCompetition sorter("../doc/test.txt");
	if(sorter.readData())
	{
		cout << "Yeah it Worked!! :)" << endl;
		if(sorter.prepareData())
		{
			cout << "Aww yeah, data copied!" << endl;
			sorter.sortData();
			sorter.outputData("stdout");
		}
	}
	return 0;
}
