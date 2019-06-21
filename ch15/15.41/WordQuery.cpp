#include"WordQuery.h"

Query::Query(const string&word) :m_q(new WordQuery(word)){}
WordQuery* WordQuery::clone()
{
	return new WordQuery(*this);
}