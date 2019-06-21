#include<memory>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string.h>

using std::vector;
class MyString
{
	//14.7
	friend std::ostream& operator<<(std::ostream&, const MyString&);
public:
	MyString() :element(nullptr), first_free(nullptr), cap(nullptr) {}
	MyString(const char*);
	MyString(const MyString&rhs) :MyString(rhs.element)
	{
		//13.47
		std::cout << "调用拷贝构造函数" << std::endl;
	}
	//13.49
	MyString(MyString&&rvalue_r) :element(rvalue_r.element),
		first_free(rvalue_r.first_free), cap(rvalue_r.cap)
	{
		rvalue_r.element = rvalue_r.first_free = rvalue_r.cap = nullptr;
	}
	MyString&operator=(MyString&&);
	MyString& operator=(MyString);
	~MyString();
	MyString& operator=(const MyString&);
private:
	std::allocator<char> alloc;

	void free();
	std::pair<char*, char*> check_copy(const char*, const char*);
	char*element;
	char*first_free;
	char*cap;
};

MyString::MyString(const char*str)
{
	size_t size = strlen(str) + 1;
	element = alloc.allocate(size);
	for (auto p = element; p - element != size;)
		alloc.construct(p++, *str++);
	first_free = element + size;
	cap = element + size;
}

MyString& MyString::operator=(const MyString&rhs)
{
	//13.47
	std::cout << "调用拷贝赋值运算符函数" << std::endl;
	auto res = check_copy(rhs.element, rhs.first_free);
	free();
	element = res.first;
	first_free = res.second;
	cap = res.second;
	return *this;
}

MyString::~MyString()
{
	free();
}

void MyString::free()
{
	if (element)
	{
		std::for_each(element, first_free, [this](char&ch) {alloc.destroy(&ch); });
		alloc.deallocate(element, cap - element);
	}
}

std::pair<char*, char*>MyString::check_copy(const char*b, const char*e)
{
	auto first = alloc.allocate(e - b);
	return{ first,std::uninitialized_copy(b,e,first) };
}

//13.49
MyString& MyString::operator=(MyString&&rvalue_r)
{
	if (this != &rvalue_r)
	{
		element = rvalue_r.element;
		first_free = rvalue_r.first_free;
		cap = rvalue_r.cap;
		rvalue_r.element = rvalue_r.first_free = rvalue_r.cap = nullptr;
	}
	return *this;
}

//13.47-48
int main()
{
	vector<MyString>vec;
	for (int i = 0; i < 3; ++i)
		vec.push_back(MyString("GOOD"));
	for (int i = 0; i < 3; ++i)
		vec.push_back(MyString("GOD"));
	for (int i = 0; i < 3; ++i)
		vec.push_back(MyString("GOLD"));
	std::cout << vec.front();
}

MyString& MyString::operator=(MyString rhs)
{
	using std::swap;
	swap(*this, rhs);
	return *this;
}

//14.7
std::ostream& operator<<(std::ostream&os, const MyString&String)
{
	os << String.element;
	return os;
}