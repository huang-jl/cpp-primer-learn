#include<iostream>
#include"16_56.h"

using std::ostream;

template<typename T>
ostream& print(ostream&os, const T&t)
{
	os << t;
	return os;
}

template<typename T,typename ...Args>
ostream& print(ostream&os,const T&t, const Args&...rest)
{
	os << t << ", ";
	return print(os, rest...);
}

template<typename ...Args>
ostream& errorMessage(ostream&os, const Args&...rest)
{
	return print(os, debug_rep(rest)...);
}

int main()
{
	int i = 10, arr[3] = { 1,2,3 };
	char str[6] = "funny";
	errorMessage(std::cerr, 42, "good", arr, str);

	return 0;
}

