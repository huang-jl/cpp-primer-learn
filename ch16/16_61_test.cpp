#include"16_61.h"
#include<string>
#include<iostream>

using std::string;
using std::cout; using std::endl;

int main()
{
	shared_ptr<string>sp = my_make_shared<string>(10, 'c');
	cout << sp << ": " << *sp << endl;

	return 0;
}