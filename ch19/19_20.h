#pragma once
#include<vector>
#include<map>
#include<set>
#include<iostream>
#include<fstream>
#include<memory>

using namespace std;

class TextQuery
{
public:
	class QueryResult;
friend ostream& print(ostream&, QueryResult);
	/***************************************/
	TextQuery() = default;
	TextQuery(ifstream&);
	QueryResult query(const string&);
private:
	shared_ptr<vector<string>>whole_text;
	map<string, set<int>>wordToSet;
};

class TextQuery::QueryResult
{
	friend ostream& print(ostream&, QueryResult);
public:
	QueryResult() = default;
	QueryResult(const string&, TextQuery*);
private:
	shared_ptr<vector<string>>sp;
	vector<vector<string>::iterator>line_iter;
	size_t show_times = 0;
	string word;
};

extern ostream& print(ostream&, TextQuery::QueryResult);
