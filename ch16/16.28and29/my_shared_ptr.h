#pragma once
#include<functional>
#include"delete.h"
template<typename T>
class my_shared_ptr
{
public:
	my_shared_ptr() = default;

	template<typename De=decltype(Delete<T>)>
	my_shared_ptr<T>(T* pointer, De f_delete = Delete<T>) : data(pointer),
					del(f_delete),ref_count(new size_t(1)) { }
	my_shared_ptr(const my_shared_ptr&rhs) :data(rhs.data), del(rhs.del), ref_count(rhs.ref_count) { ++(*ref_count); }
	my_shared_ptr& operator=(const my_shared_ptr&rhs);

	~my_shared_ptr() { decrease_ref(); }

	template<typename De = decltype(Delete<T>)>
	void reset(T * new_pointer= nullptr, De f_delete = Delete<T>);
	T& operator*()const { return *data;}
	T* operator->() const{ return &this->operator*(); }
private:
	void decrease_ref();
	T* data = nullptr;
	std::function<void(T*)>del;
	size_t* ref_count = nullptr;
};

template<typename T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr&rhs)
{
	if (this != &rhs)
	{
		decrease_ref();
		ref_count = rhs.ref_count;
		data = rhs.data;
		del = rhs.del;
		return *this;
	}
}

template<typename T>
void my_shared_ptr<T>::decrease_ref()
{
	if (!ref_count)
		return;
	if (!(--(*ref_count)))
	{
		del(data);
		delete ref_count;
	}
}

template<typename T>
template<typename De>
void my_shared_ptr<T>::reset(T* new_pointer, De f_delete)
{
	decrease_ref();
	data = new_pointer;
	del = f_delete;
}