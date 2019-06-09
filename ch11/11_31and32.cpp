#include<map>
#include<string>
#include<iostream>

using namespace std;

void f()
{
	multimap<string, string>author_work{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency" }
	};
	/*11.31
	string author;
	string work;
	auto iter = author_work.find(author);
	auto count = author_work.count(author);

	while (count)
	{
		if (iter->second == work)
			author_work.erase(iter);
		++iter;
		--count;
	}*/

	/*11.32
	auto iter = author_work.begin();
	while (iter != author_work.end())
	{
		auto count = author_work.count(iter->first);
		cout << "author:" << iter->first<<(count>1?" works:":" work:");
		while (count)
		{
			cout << iter->second << " ";
			++iter;
			--count;
		}
		cout << endl;
	}*/
	
}