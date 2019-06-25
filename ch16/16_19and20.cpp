#include<iostream>
#include<vector>

using std::vector;
using std::cout; using std::endl;

//16.19
/*template<typename T>
void printContainer(const T&cont)
{
	using size_type = typename T::size_type;
	for (size_type i = 0; i < cont.size(); ++i)
		cout << cont[i] << " ";
	cout << endl;
}*/

//16.20
template<typename T>
void printContainer(const T&cont)
{
	using size_type = typename T::size_type;
	for (auto beg=cont.begin(),end=cont.end();beg!=end;++beg)
		cout << *beg << " ";
	cout << endl;
}

int main()
{
	vector<int>vec = { 1,2,3,6,5,4,9,8,7 };
	printContainer(vec);
	return 0;
}