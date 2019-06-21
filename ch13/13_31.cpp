#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using std::string;

class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string&s=string()) :m_i(0), ps(new string(s)) {}
	HasPtr(const HasPtr&);
	HasPtr& operator =(const HasPtr&);
	bool operator<(const HasPtr&);
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

bool HasPtr::operator<(const HasPtr&rhs)
{
	return *ps < *rhs.ps;
}

void swap(HasPtr&lhs, HasPtr&rhs)
{
	using std:: swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.m_i, rhs.m_i);
	std::cout << "调用HasPtr的swap函数" << std::endl;
}

int main(int argc,char*argv[])
{
	using std::swap;
	std::vector<HasPtr>vec(120,HasPtr("good"));
	for (int i = 0; i < 100; ++i)
		vec.push_back(HasPtr("asdsa"));
	std::sort(vec.begin(), vec.end());
	return 0;
}