#include<map>
#include<string>
#include<iostream>

using namespace std;

void count_word()
{
	map<string, size_t>word_count;
	string word;
	while (cin >> word)
	{
		auto ret = word_count.insert({ word,1 });
		if (!ret.second)
			++(ret.first->second);
	}
}