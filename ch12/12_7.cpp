#include<vector>
#include<iostream>
#include<memory>

using namespace std;

using shared_p = shared_ptr<vector<int>>;

shared_p create()
{
	return make_shared<vector<int>>();
}

void add(shared_p pv)
{
	for (int i; cin >> i; pv->push_back(i));
}

void print(shared_p pv)
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
}