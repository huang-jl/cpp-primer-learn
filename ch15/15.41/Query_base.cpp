#include"Query_base.h"

ostream& operator<<(ostream&os, const Query&q)
{
	os << q.rep();
	return os;
}

Query::Query(const Query&rhs) :m_q(rhs.m_q->clone()) {}

Query& Query::operator=(const Query&rhs)
{
	delete m_q;
	m_q = rhs.m_q->clone();
	return *this;
}