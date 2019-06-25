#pragma once
#include<sstream>
#include<string>

using std::string;
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
		oss << " context:" << debug_rep(*p);
	else
		oss << " null pointer";
	return oss.str();
}

string debug_rep(char*p)
{
	return debug_rep(string(p));
}

string debug_rep(const char*p)
{
	return debug_rep(string(p));
}