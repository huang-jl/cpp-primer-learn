#include<ctime>
#include<iostream>
using std::cout; using std::endl;
class numbered
{
public:
	unsigned mysn;
	numbered() :mysn(1000) {}
	//13.15
	numbered(const numbered&) { srand(time(0)); mysn = rand() % 10000; }
};

void f(const numbered s) { cout << s.mysn << endl; }

int main()
{
	numbered a, b = a, c = b;
	f(a); f(b); f(c);
}