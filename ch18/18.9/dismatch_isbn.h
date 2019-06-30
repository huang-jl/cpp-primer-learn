#pragma once
#include<stdexcept>
#include<string>

using std::string;
class dismatch_isbn :public std::logic_error
{
public:
	dismatch_isbn(const string&s) :logic_error(s) {}
	dismatch_isbn(const string&s, const string&lhs, const string&rhs) :logic_error(s),
		left(lhs), right(rhs) {}
	const string left;
	const string right;
};