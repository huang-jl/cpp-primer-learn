#pragma once
#include"BinaryQuery.h"

class AndQuery:public BinaryQuery
{
public:
	AndQuery(const Query& left, const Query& right, const string& ch) :BinaryQuery(left, right, ch) {}
	QueryResult equl(const TextQuery&)const override;
	AndQuery* clone()override;
};