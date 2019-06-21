#include"13_39.h"
#include<iostream>
using namespace std;

int main()
{
	StrVec sv, sv1{"good","nice"};
	for (string word; cin >> word; sv.push_back(word));
	cout << "sv.size()=" << sv.size() << endl;
	cout << "sv.capacity()=" << sv.capacity() << endl;
	sv.resize(20, "good");
	sv.reserve(35);
	for (auto b = sv.begin(); b != sv.end(); ++b)
		cout << *b << endl;
	cout << "sv.size()=" << sv.size() << endl;
	cout << "sv.capacity()=" << sv.capacity() << endl;
}