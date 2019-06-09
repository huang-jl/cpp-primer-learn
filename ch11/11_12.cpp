#include<string>
#include<utility>
#include<vector>
#include<iostream>

using namespace std;

void pairWithStringAndInt()
{
	vector<pair<string,int>>vp;
	string str; int i;
	while (cin >> str >> i)
	{
		vp.push_back(pair<string, int>(str, i));
		//vp.push_back(make_pair(str, i));
		//vp.emplace_back(str, i);
	}

}