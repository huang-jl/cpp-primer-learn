#pragma once
#include<memory>
using std::shared_ptr;
 
template<typename T,typename ...Args>
shared_ptr<T> my_make_shared(Args&&...args)
{
	return shared_ptr<T>(new T(args...));
}