#include<iostream>

using namespace std;

void inputString()
{
	char *str = new char[100];
	cin >> str;
	cout << str << endl;
	delete[]str;
}