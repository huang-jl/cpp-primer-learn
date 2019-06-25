#pragma once
#include"delete.h"
#include<functional>
#include<exception>
#include<iostream>
using namespace std;

template<typename T,typename De=decltype(Delete<T>)*>
class my_unique_ptr
{
public:
	my_unique_ptr() = default;
	my_unique_ptr(T*pointer, De f_delete = Delete<T>) :data(pointer), del(f_delete) {}
	my_unique_ptr(const my_unique_ptr&) = delete;
	my_unique_ptr& operator=(const my_unique_ptr&) = delete;
	my_unique_ptr& operator = (my_unique_ptr&&rhs)noexcept
	{
		delete data;
		data = std::move(rhs.data);
		del = std::move(rhs.del);
		rhs.data = nullptr;
		return *this;
	}
	~my_unique_ptr() { del(data); }

	T& operator*() { return *data;}
	T* operator->() { return &this->operator*(); }

private:
	T* data = nullptr;
	De del;
};
