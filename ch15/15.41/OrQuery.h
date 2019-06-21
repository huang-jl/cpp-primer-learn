#pragma once
#include"BinaryQuery.h"

class OrQuery:public BinaryQuery
{
public:
	OrQuery(const Query& left, const Query& right, const string& ch) :BinaryQuery(left, right, ch) {}
	QueryResult equl(const TextQuery&)const override;
	OrQuery* clone()override;
};