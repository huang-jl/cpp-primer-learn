#include<string>
#include<iostream>
#include<typeinfo>

void f(int, double) {}
class Test
{};

int main()
{
	Test t;
	std::string str;
	int i, *p = nullptr;
	double d;
	std::cout << "(type)f()= "<<typeid(f).name() << std::endl;
	std::cout << "(type)str= " << typeid(str).name() << std::endl;
	std::cout << "(type)i= " << typeid(i).name() << std::endl;
	std::cout << "(type)p= " << typeid(p).name() << std::endl;
	std::cout << "(type)t= " << typeid(t).name() << std::endl;
	std::cout << "(type)d= " << typeid(d).name() << std::endl;

	return 0;
}