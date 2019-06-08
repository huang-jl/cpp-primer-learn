#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;
void biggies(vector<string>&words, vector<string>::size_type sz)
{
	sort(words.begin(), words.end());
	/*stable_sort(words.begin(), words.end(),
		[](const string&s1, const string&s2) {return s1.size() < s2.size(); });*/
	auto iter_end = partition(words.begin(), words.end(),
		[sz](string&s) {return s.size() >= sz; });
	auto iter = words.begin();
	while (iter != iter_end)
	{
		cout << *iter << " ";
		++iter;
	}
	cout << endl;
}