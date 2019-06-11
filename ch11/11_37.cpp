#include<unordered_map>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

using namespace std;

//单词计数
void count_word()
{
	unordered_map<string, size_t>word_count;
	string word;
	while (cin >> word)
		++word_count.insert({ word,0 }).first->second;
	for (const auto &c : word_count)
		cout << c.first << "appears" << c.second << (c.second > 1 ? "times" : "time") << endl;
}

//单词转换
void buildMap(unordered_map<string, string>&rules, ifstream&file_rules)
{
	for (string source_word, final_word; file_rules >> source_word && getline(file_rules, final_word);)
	{
		if (final_word.size() > 1)
		{
			final_word = final_word.substr(1, final_word.find_last_not_of(' '));
			rules.insert({ source_word,final_word });
		}
	}
}

const string & trans(const string&word, unordered_map<string, string>&rules)
{
	auto iter = rules.find(word);
	return (iter == rules.end() ? word : iter->second);
}

void word_transform(ifstream&file_rules, ifstream&file_text)
{
	unordered_map<string, string>rules;
	buildMap(rules, file_rules);
	string text, word;
	while (getline(file_text, text))
	{
		istringstream iss(text);
		while (iss >> word)
		{
			cout << trans(word, rules) << " ";
		}
		cout << endl;
	}
}

