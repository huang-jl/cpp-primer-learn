#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

//set���ŵ㣺
//1.����������Զ��ᰴ��˳������
//2.set���������ظ���Ԫ��
//3.set�����Ԫ�صĴ��۸���

void addWord()
{
	vector<string>word_list;

	for (string word; cout << "��Ҫ��ӵĵ��ʣ�\n", cin >> word && word != "@q";)
	{
		if (word_list.end() == find(word_list.begin(), word_list.end(), word))
			word_list.push_back(word);
	}
}