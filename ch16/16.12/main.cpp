#include"Blob.h"
#include"BlobPtr.h"
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
	BlobPtr<string>StrBlobPtr(StrBlob);
	cout << *(++StrBlobPtr) << endl;

	const Blob<string>ConstBlob(Blob<string>({"s","ss" ,"sss" ,"ssss" ,"sssss" ,"ssssss" ,"sssssss" ,"ssssssss" }));
	cout << "ConstBlob.front()=" << ConstBlob.front() << endl;
	cout << "ConstBlob.back()=" << ConstBlob.back() << endl;

	const BlobPtr<string>ConstBlobPtr_5(ConstBlob,5);
	const BlobPtr<string>ConstBlobPtr_0(ConstBlob);
	cout <<"*ConstBlobPtr_5="<< *ConstBlobPtr_5 << endl;
	cout << "ConstBlobPtr_0==ConstBlobPtr_5=" << static_cast<bool>(ConstBlobPtr_0 == ConstBlobPtr_5) << endl;
	cout << "ConstBlobPtr_0!=ConstBlobPtr_5=" << static_cast<bool>(ConstBlobPtr_0 != ConstBlobPtr_5) << endl;
	cout << "ConstBlobPtr_0<ConstBlobPtr_5=" << static_cast<bool>(ConstBlobPtr_0 < ConstBlobPtr_5) << endl;
	cout << "ConstBlobPtr_0>ConstBlobPtr_5=" << static_cast<bool>(ConstBlobPtr_0 > ConstBlobPtr_5) << endl;
	return 0;
}