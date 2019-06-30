#include"NotQuery.h"

Query operator~(const Query&q)
{
	return std::shared_ptr<Query_base>(new NotQuery(q));
}

QueryResult NotQuery::equl(const TextQuery&text)const
{
	auto res = base.equl(text);
	shared_ptr<set<size_t>>line_new(new set<size_t>);
	auto beg = res.begin(), end = res.end();
	size_t n = res.get_file()->size();
	for (int i = 0; i < n; ++i)
	{
		if (beg == end)
		{
			line_new->insert(i);
			continue;
		}
		if (i != *beg)
			line_new->insert(i);
		if (i == *beg)
			++beg;
	}
	return QueryResult(rep(), line_new, res.get_file());
}