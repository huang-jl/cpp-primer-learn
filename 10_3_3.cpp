#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

void longer_than_six()
{
	vector<string>vs;
	cout << count_if(vs.begin(), vs.end(), [](string&s) {return s.size() > 6; }) << endl;
}

void f10_21()
{
	int i = 42;
	auto f = [&i]() {return i > 0 ? !--i : !i; }
}