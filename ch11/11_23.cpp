#include<map>
#include<string>
#include<iostream>

using namespace std;

void addChildren(multimap<string,string>&fam)
{
	for (string last; cout << "�����뺢�ӵ���\n", cin >> last && last != "@q";)
		for (string first; cout << "�����뺢�ӵ���\n", cin >> first && first != "@q";)
			fam.emplace(last, first);
}

void childMultiMap()
{
	multimap<string, string>fam;
	addChildren(fam);
}