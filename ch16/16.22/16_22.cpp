#include"16_22.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>

using std::cout; using std::endl;

TextQuery::TextQuery() :file(DBG_NEW vector<string>, DebugDelete()) {}

TextQuery::TextQuery(const string&file_name):TextQuery()
{
	std::ifstream ifs(file_name);
	if (ifs.fail())
	{
		std::cerr << "文件" << file_name << "打开失败\n";
		return;
	}
	size_t line_num = 0;
	for (string line_text; std::getline(ifs, line_text); ++line_num)
	{
		file->emplace_back(line_text);
		string line;
		std::remove_copy_if(line_text.begin(), line_text.end(), std::back_inserter(line), ispunct);
		std::istringstream iss(line);
		for (string word; iss >> word;)
		{
			if (!wm[word])
				wm[word].reset(DBG_NEW set<size_t>,DebugDelete());
			wm[word]->insert(line_num);
		}
	}
}

QueryResult TextQuery::query(const string&word)const
{
	static shared_ptr<set<size_t>> nodata(DBG_NEW set<size_t>,DebugDelete());
	auto res = wm.find(word);
	if (res == wm.end())
		return QueryResult(word, nodata, file);
	else
		return QueryResult(word, res->second, file);
}

void print_query(const QueryResult&res)
{
	cout << res.word << "occurs " << res.line->size() << (res.line->size() > 1 ? " times" : " time") << endl;
	for (const auto& line_no : *res.line)
	{
		cout << "(" << line_no + 1 << " line) " << res.text->at(line_no) << endl;
	}
}