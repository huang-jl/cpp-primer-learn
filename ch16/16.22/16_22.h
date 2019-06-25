#pragma once
#include<string>
#include<vector>
#include<set>
#include<memory>
#include<map>
#include"16_21.h"
#include"debug_new.h"

using std::string;
using std::vector;
using std::set;
using std::shared_ptr;
using std::map;
class QueryResult;
class TextQuery
{
public:
	TextQuery();
	TextQuery(const string&);

	QueryResult query(const string&)const;
private:
	shared_ptr<vector<string>>file;
	map<string, shared_ptr<set<size_t>>>wm;
};

class QueryResult
{
	friend void print_query(const QueryResult&);
public:
	QueryResult(const string&f_word, shared_ptr<set<size_t>> line_num, shared_ptr<vector<string>> p_text)
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