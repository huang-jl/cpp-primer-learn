#include<memory>
#include<vector>
#include<string>
#include"14_30.h"

using namespace std;

//StrBlob
StrBlob::StrBlob() :data(make_shared<vector<string>>()) {};
StrBlob::StrBlob(initializer_list<string> li) :data(make_shared<vector<string>>(li)) {}

void StrBlob::pop_back()
{
	check(0, "容器末尾没有元素");
	data->pop_back();
}

string& StrBlob::front()
{
	check(0, "容器开头没有元素");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "容器末尾没有元素");
	return data->back();
}

const string& StrBlob::front()const
{
	check(0, "容器开头没有元素");
	return data->front();
}

const string& StrBlob::back()const
{
	check(0, "容器末尾没有元素");
	return data->back();
}

void StrBlob::check(size_type i, const string&msg)const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

//StrBlobPtr
string& StrBlobPtr::deref()const
{
	auto p = check("下标越界");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check("下标越界");
	++curr;
	return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(const string&msg)const
{
	auto p = wp.lock();
	if (!p)
		throw runtime_error("未绑定的StrBlobPtr");
	if (curr >= p->size())
		throw out_of_range(msg);
	return p;
}



