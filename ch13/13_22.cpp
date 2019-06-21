#include<string>

using std::string;

class HasPtr
{
public:
	HasPtr() :m_i(0), ps(nullptr) {}
	HasPtr(const HasPtr&);
	HasPtr& operator =(const HasPtr&);
	~HasPtr() { delete ps; }
private:
	int m_i;
	string* ps;
};

HasPtr::HasPtr(const HasPtr&hp)
{
	m_i = hp.m_i;
	ps = new string{ *hp.ps };
	char *p;
}

HasPtr& HasPtr::operator=(const HasPtr&hp)
{
	m_i = hp.m_i;
	string *newp = new string(*hp.ps);
	delete ps;
	ps = newp;
	return *this;
}