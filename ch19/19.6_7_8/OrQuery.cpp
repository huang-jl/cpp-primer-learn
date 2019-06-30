#include"OrQuery.h"

Query operator|(const Query&lhs, const Query&rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs, "|"));
}

QueryResult OrQuery::equl(const TextQuery&text)const
{
	auto resleft = lhs.equl(text), resright = rhs.equl(text);
	shared_ptr<set<size_t>>line_new(new set<size_t>);
	line_new->insert(resleft.begin(), resleft.end());
	line_new->insert(resright.begin(), resright.end());
	return QueryResult(rep(), line_new, resleft.get_file());
}