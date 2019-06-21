#pragma once
#include"Query_base.h"

class NotQuery :public Query_base
{
public:
	NotQuery(const Query&q) :base(q) {}
	string rep() const override { return "(~ " + base.rep() + ")"; }
	QueryResult equl(const TextQuery&)const override;
private:
	Query base;
};