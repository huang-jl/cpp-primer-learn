#include"12_19.h"
#include"12_19.h"
#include<fstream>
#include<iostream>

using namespace std;

int main()
{
	ifstream ifs("input.txt");
	StrBlob text;

	for (string line; getline(ifs, line); text.push_back(line));
	StrBlobPtr tp = text.begin();
	size_t count = text.size();
	while (count)
	{
		cout << tp.deref() << endl;
		tp = tp.incr();
		--count;
	}
}