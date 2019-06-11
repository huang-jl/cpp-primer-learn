#pragma once
#include<memory>
#include<vector>
#include<string>

using namespace std;

class StrBlobPtr;
class StrBlob
{
public:
	friend class StrBlobPtr;
	using size_type = vector<string>::size_type;
	StrBlob();
	StrBlob(initializer_list<string>);
	size_type size() { return data->size(); }
	bool empty() { return data->empty(); }
	void push_back(const string&str) { data->push_back(str); }
	void pop_back();
	string& front();
	string& back();
	const string& front()const;
	const string& back()const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	shared_ptr<vector<string>>data;
	void check(size_type i, const string&msg)const;
};

class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &s, size_t t = 0) :wp(s.data), curr(t) {}
	string& deref()const;
	StrBlobPtr& incr();
private:
	shared_ptr<vector<string>> check(const string&msg)const;
	weak_ptr<vector<string>>wp;
	vector<string>::size_type curr;
};
