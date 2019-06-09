#include<map>
#include<string>
#include<iostream>

using namespace std;

void addChildren(multimap<string,string>&fam)
{
	for (string last; cout << "请输入孩子的姓\n", cin >> last && last != "@q";)
		for (string first; cout << "请输入孩子的名\n", cin >> first && first != "@q";)
			fam.emplace(last, first);
}

void childMultiMap()
{
	multimap<string, string>fam;
	addChildren(fam);
}