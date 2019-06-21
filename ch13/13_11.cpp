#include<string>

using namespace std;
class HasPtr
{
public:
	HasPtr(const string&s = string()) :ps(new string(s)), i(0) {}
	~HasPtr();
private:
	string* ps;
	int i;
};

HasPtr::~HasPtr()
{
	delete ps;
}