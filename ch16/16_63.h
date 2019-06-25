#pragma once
#include<vector>
using std::vector;

template<typename T>
size_t my_count(vector<T>&vec, const T& val)
{
	size_t i = 0;
	for (const auto&ele : vec)
		if (ele == val)
			++i;
	return i;
}

template<>
size_t my_count(vector<const char*>&vec,const char*const&val)
{
	size_t i = 0;
	for (const auto&ele : vec)
		if (strcmp(ele, val))
			++i;
	return i;
}