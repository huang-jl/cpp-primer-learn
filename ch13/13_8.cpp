#include<string>

using namespace std;
class HasPtr
{
public:
	HasPtr(const string&s = string()) :ps(new string(s)), i(0) {}
	HasPtr& operator = (const HasPtr&);
private:
	string* ps;
	int i;
};

HasPtr& HasPtr::operator=(const HasPtr&hp)
{
	i = hp.i;
	delete ps;
	ps = new string(*hp.ps);
	return *this;
}