#include<map>
#include<string>
#include<set>
#include<algorithm>
#include<iostream>

using namespace std;

//11.3
void count_word()
{
	map<string, size_t>word_count;
	string word;
	while (cin >> word)
	{
		++word_count[word];
	}
	for (const auto& pair : word_count)
		cout << pair.first << "appears" << pair.second << (pair.second > 1 ? "times" : "time") << endl;
}

//11.4
void change_normal(string&word)
{
	for (auto &c : word)
		c = tolower(c);
	word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
}

void count_word_v2()
{
	map<string, size_t>word_count;
	string word;
	while (cin >> word)
	{
		change_normal(word);
		++word_count[word];
	}
}
