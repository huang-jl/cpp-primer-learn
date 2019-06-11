#include<string>
#include<memory>
#include<iostream>

using namespace std;
void linkTwoStr()
{
	//11.23.1
	const char sr1[] = "Hello, ";
	const char sr2[] = "my name is huang.";
	char* sr = new char[25];
	int i,j;
	for (i = 0; i < 7; ++i)
		sr[i] = sr1[i];
	for (j = 0; j < 18; ++j)
		sr[i + j] = sr2[j];
	cout << sr << endl;
	delete[]sr;

	//11.23.2
	string str1("Hello, ");
	string str2("my name is huang.");
	string s = str1 + str2;
	char *str = new char[str1.size() + str2.size() + 1];
	for (auto c = s.begin(); c != s.end(); ++c)
		str[c - s.begin()] = *c;
	str[str1.size() + str2.size()] = 0;
	cout << str << endl;
	delete[]str;
}