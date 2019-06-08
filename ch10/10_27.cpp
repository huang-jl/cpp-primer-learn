#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

template<class T>
void show(const T& t)
{
	for (const auto& c : t)
	{
		cout << c << " ";
	}
}

void f10_27()
{
	vector<string>vs = { "aa","bbb","aa","red","aa","red","bbb" };
	vector<string>vs_copy;
	sort(vs.begin(), vs.end());
	unique_copy(vs.begin(), vs.end(), back_inserter(vs_copy));
	show(vs_copy);
}