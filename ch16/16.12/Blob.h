#pragma once
#include<memory>
#include<vector>
#include<string>

using std::shared_ptr;
using std::vector;
using std::string;

template<typename> class BlobPtr;

template<typename T>
class Blob
{
	friend BlobPtr<T>;
public:
	using size_type=typename vector<T>::size_type;
	Blob() :data(std::make_shared<vector<T>>()) {}
	Blob(const Blob&rhs) :data(rhs.data) {}
	Blob(std::initializer_list<T>li);
	Blob&operator=(const Blob&rhs) { data = rhs.data; return *this; }

	size_type size()const { return data->size(); }
	bool empty()const { return data->empty(); }

	T& front() { check(0, "front on empty Blob."); return data->front(); }
	const T& front()const { check(0, "front on empty Blob."); return data->front();}
	T& back() { check(0, "back on empty Blob."); return data->back(); }
	const T& back()const { check(0, "back on empty Blob."); return data->back(); }
	T& operator[](size_type n) { check(n, "subscript out of range."); return data[n]; }

	void push_back(const T&t) { data->push_back(t); }
	void push_back(T&&t) { data->push_back(std::move(t)); }
	void pop_back();
private:
	shared_ptr<vector<T>>data;
	void check(size_t, const string&)const;
};

template<typename T>
void Blob<T>::check(size_t n, const string&msg)const
{
	if (n >= data->size())
		throw std::out_of_range(msg);
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop on empty Blob.");
	data->pop_back();
}

template<typename T>
Blob<T>::Blob(std::initializer_list<T>li) :data(std::make_shared<vector<T>>(li)) {}