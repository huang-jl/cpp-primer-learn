#pragma once
#include"Query_base.h"

class BinaryQuery :public Query_base
{
public:
	BinaryQuery(const Query& left, const Query& right, const string& ch) :lhs(left), rhs(right), ope(ch) {}
	string rep()const  override{ return "(" + lhs.rep() + " " + ope + " " + rhs.rep() + ")"; }
protected:
	Query lhs, rhs;
	string ope;
};