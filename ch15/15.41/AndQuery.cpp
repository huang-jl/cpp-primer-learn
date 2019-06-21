#include"AndQuery.h"
#include<algorithm>
#include<iterator>

Query operator&(const Query&lhs, const Query&rhs)
{
	return (new AndQuery(lhs, rhs, "&"));
}

QueryResult AndQuery::equl(const TextQuery&text)const
{
	auto resleft = lhs.equl(text),resright=rhs.equl(text);
	shared_ptr<set<size_t>>line_new(new set<size_t>);
	std::set_intersection(resleft.begin(), resleft.end(), resright.begin(), resright.end(),
		std::inserter<set<size_t>>(*line_new, line_new->begin()));
	return QueryResult(rep(), line_new, resleft.get_file());
}

AndQuery* AndQuery::clone()
{
	return new AndQuery(*this);
}