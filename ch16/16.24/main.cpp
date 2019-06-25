#include"Blob.h"
#include"BlobPtr.h"
#include<iostream>
#include<vector>

using std::cout; using std::endl;
using std::vector;

int main()
{
	vector<string>vec = { "s","ss","sss","ssss" };
	Blob<string>StrBlob(vec.begin(), vec.end());
	BlobPtr<string>StrBlobPtr(StrBlob,3);
	cout << *StrBlobPtr << endl;
	return 0;
}