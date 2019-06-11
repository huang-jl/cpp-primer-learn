#include"12_27.h"
#include<sstream>
TextQuery::TextQuery(ifstream&ifs)
{
	int i = 1;
	whole_text = make_shared<vector<string>>();
	for (string line; getline(ifs, line); whole_text->push_back(line),++i)
	{
		istringstream iss(line);
		string word;
		while (iss >> word)
			wordToSet[word].emplace(i);
	}
}

QueryResult TextQuery::query(const string&str)
{
	return QueryResult(str, this);
}

QueryResult::QueryResult(const string&str, TextQuery*pt)
{
	word = str;
	sp = pt->whole_text;
	auto iter_map = pt->wordToSet.find(str);
	if (iter_map != pt->wordToSet.end())
	{
		auto iter_vector = sp->begin();
		for (const auto&line_number : iter_map->second)
			line_iter.push_back(iter_vector + line_number - 1);
		show_times = iter_map->second.size();
	}
}

ostream& print(ostream&os, QueryResult result)
{
	os << result.word << " appears " << result.show_times << (result.show_times > 1 ? " times" : " time") << endl;
	for (const auto&iter : result.line_iter)
	{
		cout << "(line " << 1 + iter - result.sp->begin() << ") " << *iter << endl;
	}
	return os;
}