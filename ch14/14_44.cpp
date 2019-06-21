#include<functional>
#include<string>
#include<map>
#include<iostream>

using std::function;
using std:: string;
using std::map;
using std::cout; using std::endl;

int add(int a, int b)
{
	return a + b;
}

int minus(int a, int b)
{
	return a - b;
}

class divide
{
public:
	int operator()(int a, int b) { return a / b; }
};


int main()
{
	auto mutiply = [](int a, int b) {return a * b; };
	map<string, function<int(int, int)>>computer;
	computer.insert({ "+",function<int(int, int)>(add) });
	computer.insert({ "-",function<int(int, int)>(minus) });
	computer.insert({ "/",function<int(int, int)>(divide()) });
	computer.insert({ "*",function<int(int, int)>(mutiply) });
	computer.insert({ "%",function<int(int, int)>(std::modulus<int>()) });
	cout << "25%3=" << computer["%"](25, 3) << endl;
	cout << "25*3=" << computer["*"](25, 3) << endl;
	cout << "25-3=" << computer["-"](25, 3) << endl;
	cout << "25/3=" << computer["/"](25, 3) << endl;
	cout << "25+3=" << computer["+"](25, 3) << endl;
	return 0;
}