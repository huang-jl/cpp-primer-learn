#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

//set的优点：
//1.保存的数据自动会按照顺序排列
//2.set不允许保存重复的元素
//3.set中添加元素的代价更低

void addWord()
{
	vector<string>word_list;

	for (string word; cout << "你要添加的单词：\n", cin >> word && word != "@q";)
	{
		if (word_list.end() == find(word_list.begin(), word_list.end(), word))
			word_list.push_back(word);
	}
}