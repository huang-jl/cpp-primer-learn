#pragma once
#include<string>
#include<vector>
#include<set>
#include<memory>
#include<map>

using std::string;
using std::vector;
using std::set;
using std::shared_ptr;
using std::map;
class QueryResult;
class TextQuery
{
public:
	TextQuery() = default;
	TextQuery(const string&);

	QueryResult query(const string&)const;
private:
	shared_ptr<vector<string>>file= std::make_shared<vector<string>>();
	map<string, shared_ptr<set<size_t>>>wm;
};

class QueryResult
{
	friend void print_query(const QueryResult&);
public:
	QueryResult(const string&f_word, shared_ptr<set<size_t>> line_num,shared_ptr<vector<string>> p_text)
		:word(f_word), line(line_num), text(p_text) {}

	set<size_t>::iterator begin() const { return line->begin(); }
	set<size_t>::iterator end() const { return line->end(); }
	shared_ptr<vector<string>> get_file() const { return text; }

private:
	string word;
	shared_ptr<vector<string>>text;
	shared_ptr<set<size_t>>line;
};

extern void print_query(const QueryResult&res);