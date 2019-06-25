#pragma once
#include<string>
#include<iostream>
#include<sstream>
using std::string;
using std::cout; using std::endl;
using std::ostringstream;

template<typename T>
string debug_rep(const T&s)
{
	ostringstream oss;
	oss << s;
	return oss.str();
}

template<typename T>
string debug_rep(T* p)
{
	ostringstream oss;
	oss << "pointer:" << p;
	if (p)
		oss << " " << debug_rep(*p);
	else
		oss << " null pointer";
	return oss.str();
}

template<>
string debug_rep(char*p)
{
	return debug_rep(string(p));
}

template<>
string debug_rep(const char*p)
{
	return debug_rep(string(p));
}
