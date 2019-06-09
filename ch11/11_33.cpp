#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;



void buildMap(map<string, string>&rule, ifstream&file_rules)
{
	string source_word, final_word;
	while (file_rules >> source_word && getline(file_rules, final_word))
	{
		//应该直接判断是否>1
		if (final_word.size() > 0)
		{
			final_word = final_word.substr(1);
			if (final_word.size() > 0)
				rule.insert({ source_word,final_word });
		}
	}
}

const string& trans_form(const string&word, map<string, string>&rule)
{
	auto iter = rule.find(word);
	return (iter == rule.end()) ? word : iter->second;
}

void word_transform(ifstream& file_rules, ifstream& file_text)
{
	map<string, string>rule;
	buildMap(rule, file_rules);
	string text;
	while (getline(file_text, text))
	{
		istringstream iss(text);
		for (string word; iss >> word; cout << trans_form(word, rule) << " ");
		cout << endl;
	}
}