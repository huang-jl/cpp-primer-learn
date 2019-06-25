#include"Blob.h"
#include<iostream>

using std::cout; using std::endl;

int main()
{
	Blob<string>StrBlob;
	for (int i = 0; i < 10; ++i)
	{
		string str(i + 1, 's');
		StrBlob.push_back(str);
	}
	for (int i = 0; i != StrBlob.size(); ++i)
		cout << StrBlob[i] << endl;
	return 0;
}