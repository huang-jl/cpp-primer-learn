#pragma once
#include"TextQuery_QueryResult.h"
#include<iostream>

using std::ostream;

class Query_base
{
	friend class Query;
public:
	virtual QueryResult equl(const TextQuery&)const =0;
	virtual string rep()const = 0;
};

class Query
{
	friend 	Query operator&(const Query&, const Query&);
	friend 	Query operator|(const Query&, const Query&);
	friend 	Query operator~(const Query&);
	friend ostream& operator<<(ostream&,const Query&);
public:
	Query(const string&);
	QueryResult equl(const TextQuery&text)const { return m_q->equl(text); }
	string rep()const { return m_q->rep(); }
private:
	Query(shared_ptr<Query_base>q) :m_q(q) {}
	shared_ptr<Query_base> m_q;
};