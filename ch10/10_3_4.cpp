#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;

bool longer_than_sz(const string&s, size_t sz)
{
	return s.size() <= sz;
}

void f10_22()
{
	vector<string>vs;
	auto f = bind(longer_than_sz, placeholders::_1, 6);
	cout << count_if(vs.begin(), vs.end(), f) << endl;;
}