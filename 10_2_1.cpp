#include<vector>
#include<numeric>

using namespace std;

void f10_3()
{
	vector<int>vi;
	int sum = accumulate(vi.begin(), vi.end(), 0);
}

void f10_4()
{
	vector<double>vi;
	double sum = accumulate(vi.cbegin(), vi.cend(), 0.0);
}