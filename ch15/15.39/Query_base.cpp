#include"Query_base.h"

ostream& operator<<(ostream&os, const Query&q)
{
	os << q.rep();
	return os;
}