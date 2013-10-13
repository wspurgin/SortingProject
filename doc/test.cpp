// Word tester cpp file

#include "Word.h"
#include <fstream>

using namespace std;

int main()
{
	cout << "Tests for Word class" << endl;
	Word a("C++");
	Word b(" is");
	Word c(" awesome!");

	cout << "cout << a should print out 'C++'" << endl; 
	cout << a << endl;
	cout << "next is cout << a << b << c" << endl;
	cout << a << b << c << endl;

	cout << "a + b = 'C++ is'" << endl;
	Word d = a + b;
	cout << d << endl;
	cout << "a += b" << endl;
	a += b;
	cout << a << endl;
	cout << "set c = b" << endl;
	c = b;
	cout << c << endl;

	cout << "Binary Tests" << endl << "a = 'c++' b = 'Python'" << endl;
	a = "c++";
	b = "Python";
	cout << "a == b ?0" << endl;
	bool temp = a == b;
	cout << temp << endl;
	cout << "a > b ?1" << endl;
	temp = a > b;
	cout << temp << endl;
	cout << "a < b ?0" << endl;
	temp = a < b;
	cout << temp << endl;
	cout << "Binary operations with char*!" << endl << "a == 'c++' ?1" << endl;
	temp = a == "c++";
	cout << temp << endl;
	cout << "b > 'python' ?0" << endl;
	temp = b > "python";
	cout << temp << endl;
	cout << "'c++' == a ?1" << endl;
	temp = "c++" == a;
	cout << temp << endl;
	cout << "char * string = 'Uhoh'" << endl << "string > b ?1" << endl;
	char* string = new char[5];
	strcpy(string, "Uhoh");
	temp = string > b;
	cout << temp << endl;
	d = string;
	cout << "Word d = string" << endl;
	cout << d << endl;
	delete [] string;

	cout << "Testing >> operator... using file 'test.txt'" << endl; 
	fstream fin("test.txt");
	Word v;
	if(fin)
	{
		cout << "File opened" << endl;
		while(fin >> v)
			cout << v << endl;
		cout << v << endl;
	}
	cout << "Operator Tests Complete for Word Class" << endl;

	cout << "Dynamic allocation testing for Word Class " << endl;

	Word* dynamic = new Word("memory");
	Word* other;
	cout << *dynamic << endl;
	other = new Word();
	*other = *dynamic;
	cout << *other << endl;
	delete other;
	cout << *dynamic << endl;

	return 0;
}
