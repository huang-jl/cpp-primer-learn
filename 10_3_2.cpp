#include<string>

using namespace std;
void f10_14()
{
	auto f=[](int a, int b)->int {return a + b; };

}

void f10_15()
{
	int i = 0;
	auto f = [i](int a)->int {return a + i; };
}

void f10_16()
{
	size_t sz;
	auto f = [sz](const string&s) {return s.size() >= sz; };
}