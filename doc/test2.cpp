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
		// cout << "Yeah it Worked!! :)" << endl;
		if(sorter.prepareData())
		{
			// cout << "Aww yeah, data copied!" << endl;
			sorter.sortData();
			cout << sorter.getCopySize() << endl;
			sorter.outputData("../doc/output.txt");
		}
	}
	return 0;
}
