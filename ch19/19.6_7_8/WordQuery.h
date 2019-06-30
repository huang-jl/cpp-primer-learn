#pragma once
#include"Query_base.h"

class WordQuery:public Query_base
{
public:
	WordQuery(const string&w) :word(w) {}
	QueryResult equl(const TextQuery&text)const override { return text.query(word); }
	string rep()const override { return word; }
private:
	string word;
};