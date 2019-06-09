#include<map>
#include<string>
#include<vector>
#include<iostream>

using namespace std;
using Family = vector<pair<string, string>>;

void addChild(map<string, Family>&fam)
{
	for (string family; cout << "请输入家庭的姓\n", cin >> family && family != "@q";)
		for (pair<string, string>p; cout << "请输入孩子的名和生日", cin >> p.first&&p.first != "@q"&&cin >> p.second;)
			fam[family].push_back(p);
}	


void family_map()
{
	map<string, Family>family_map;
	addChild(family_map);
}