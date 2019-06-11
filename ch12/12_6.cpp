#include<vector>
#include<iostream>

using namespace std;

vector<int>* create()
{
	return new vector<int>;
}

void add(vector<int>*pv)
{
	for (int i; cin >> i; pv->push_back(i));
}

void print(vector<int>*pv)
{
	for (const auto& c : *pv)
	{
		cout << c << " ";
	}
	cout << endl;
}

void run()
{
	auto pv = create();
	add(pv);
	print(pv);
	delete pv;
}