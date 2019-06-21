#include<string>

using std::string;

class HasPtr
{
public:
	HasPtr(const string& s = string()) :ps(new string(s)), use(new size_t(1)), m_i(0) {}
	HasPtr(const HasPtr&hp);
	HasPtr& operator =(const HasPtr&);
	~HasPtr();

private:
	string *ps;
	size_t *use;
	int m_i;
};

inline HasPtr::HasPtr(const HasPtr&hp)
{
	ps = hp.ps;
	m_i = hp.m_i;
	use = hp.use;
	++*use;
}

HasPtr& HasPtr::operator=(const HasPtr&rhs)
{
	if (--*use == 0)
	{
		delete use;
		delete ps;
	}
	use = rhs.use;
	ps = rhs.ps;
	m_i = rhs.m_i;
	++*use;
	return *this;
}

inline HasPtr::~HasPtr()
{
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
}