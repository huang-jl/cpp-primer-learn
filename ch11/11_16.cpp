#include<map>
#include<iostream>

using namespace std;

void f()
{
	map<int, int>m;
	auto c=m.insert(pair<int, int>(3, 3));
}