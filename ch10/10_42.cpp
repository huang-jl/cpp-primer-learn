#include<list>
#include<string>

using namespace std;

void elimDumps(list<string>&words)
{
	words.sort();
	words.unique();
}