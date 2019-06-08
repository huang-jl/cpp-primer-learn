#include<iterator>
#include<vector>
#include<list>
#include<iostream>
#include<algorithm>

using namespace std;
void f10_34and35()
{
	vector<int>vi = { 1,2,3,4,5,6,7,8,9 };
	auto cr_iter = vi.crbegin();
	while (cr_iter != vi.crend())
		cout << *cr_iter++ << " ";
	cout << endl;
	auto c_iter = vi.cend() - 1;
	while (c_iter != vi.cbegin())
		cout << *c_iter-- << " ";
	cout << *c_iter << endl;
}

void f10_36()
{
	list<int>i_list = { 1,0,1,2,3,5,40,0,98,4,2,0,1,2 };
	auto last0_iter = find(i_list.rbegin(), i_list.rend(), 0);
	cout << distance(last0_iter, i_list.rend());
}

void f10_37()
{
	vector<int>vi = { 1,2,3,4,5,6,7,8,9,10 };
	list<int>i_list;
	auto b_iter = vi.rbegin();
	auto e_iter = vi.rend();
	b_iter += 2;
	e_iter -= 3;
	copy(b_iter, e_iter, back_inserter(i_list));
}