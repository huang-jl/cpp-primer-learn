#include<map>
#include<list>

using namespace std;

//hw 11.9
void connectList()
{
	map<string, list<int>>wordToList;
}

//hw11.10
//vector<int>::iterator到int的map可以
//前提是，要是同一个vector<int>的迭代器，这样才能比较大小
//list<int>::iterator到int的map不行，其迭代器不能比较大小