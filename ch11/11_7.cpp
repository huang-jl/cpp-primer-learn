#include<map>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

void addChild(map<string,vector<string>>&fam)
{
	for (string family; cout << "请输入家庭的姓\n", cin >> family && family != "@q";)
		for (string child; cout << "请输入孩子的名字\n", cin >> child && child != "@q";)
			fam[family].push_back(child);
}


void family_map()
{
	map<string, vector<string>>family_map;
	addChild(family_map);
}