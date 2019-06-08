#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

void showVector(const vector<string>& vs)
{
	for (const auto &c : vs)
		cout << c << " ";
	cout << endl;
}

void f10_9(vector<string>&vs)
{
	vs.reserve(15);
	string word;
	while (cin >> word)
		vs.push_back(word);
	showVector(vs);
	sort(vs.begin(), vs.end());
	showVector(vs);
	auto iter = unique(vs.begin(), vs.end());
	showVector(vs);
	cout << vs.size() << endl;
	vs.erase(iter, vs.end());
	showVector(vs);
}

bool isShoter(const string &vs1, const string &vs2)
{
	return vs1.size() < vs2.size();
}

void f10_11()
{
	vector<string>vs;
	f10_9(vs);
	stable_sort(vs.begin(), vs.end(), isShoter);
	showVector(vs);
}
//----------------------------------------------------
//10.13Ìâ
bool longer_than_five(const string&s)
{
	return s.size() >= 5;
}

void f10_13()
{
	vector<string>vs = { "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
	auto iter_end = partition(vs.begin(), vs.end(), longer_than_five);
	auto iter = vs.begin();
	while (iter != iter_end)
	{
		cout << *iter << endl;
		++iter;
	}
}