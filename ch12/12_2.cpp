#include<memory>
#include<vector>
#include<string>

using namespace std;
class StrBlob
{
public:
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

private:
	shared_ptr<vector<string>>data;
	void check(size_type i, const string&msg)const;
};

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
