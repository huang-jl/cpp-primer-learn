#pragma once
#include"Blob.h"

using std::weak_ptr;

template<typename T>class BlobPtr;

/*template<typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T>
bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T>
bool operator< (const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T>
bool operator> (const BlobPtr<T>&, const BlobPtr<T>&);
*/

template<typename T>
class BlobPtr
{
	using size_type =typename vector<T>::size_type;
	//template<typename T>
	friend bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
	//template<typename T>
	friend bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
	//template<typename T>
	friend bool operator< (const BlobPtr<T>&, const BlobPtr<T>&);
	//template<typename T>
	friend bool operator> (const BlobPtr<T>&, const BlobPtr<T>&);
public:
	BlobPtr(const Blob<T>&b,size_type n=0):wptr(b.data),pos(n){}
	BlobPtr(const BlobPtr&rhs) :wptr(rhs.wptr),pos(rhs.pos) {}
	BlobPtr& operator=(const BlobPtr&rhs) { wptr = rhs.data; return *this; }

	BlobPtr& operator++() { check(pos + 1, "pointer out of range."); ++pos; return *this; }
	BlobPtr operator++(int)
	{
		BlobPtr copy = *this;
		check(pos + 1, "pointer out of range.");
		pos++;
		return copy;
	}

	T& operator*() { return (*check(pos, "dereference out of range."))[pos]; }
	const T& operator*() const{ return (*check(pos, "dereference out of range."))[pos]; }
private:
	shared_ptr<vector<T>> check(size_type n,const string&)const;
	weak_ptr<vector<T>>wptr;
	size_type pos;
};

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_type n,const string&msg)const
{
	if (wptr.lock())
	{
		if (n >= wptr.lock()->size())
			throw std::out_of_range(msg);
	}
	return wptr.lock();
}

template<typename T>
bool operator==(const BlobPtr<T>&lhs, const BlobPtr<T>&rhs)
{
	return (lhs.wptr.lock() == rhs.wptr.lock()&&lhs.pos == rhs.pos);
}

template<typename T>
bool operator!=(const BlobPtr<T>&lhs, const BlobPtr<T>&rhs)
{
	return !(lhs == rhs);
}

template<typename T>
bool operator<(const BlobPtr<T>&lhs, const BlobPtr<T>&rhs)
{
	return(lhs.wptr.lock() == rhs.wptr.lock() &&lhs.pos < rhs.pos);
}

template<typename T>
bool operator>(const BlobPtr<T>&lhs, const BlobPtr<T>&rhs)
{
	return !(lhs < rhs);
}
