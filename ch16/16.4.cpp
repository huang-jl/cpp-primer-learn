#include<vector>
#include<list>

using std::vector; using std::list;

template<typename T,typename U>
T find(T first,T last,const U&value)
{
	for (; first != last; ++first)
	{
		if (*first == value)
			return first;
	}
	return last;
}

int main()
{
	vector<int>vec = { 6,2,5,8,7,9,6,3,12 };
	list<int>lis = { 15,6,98,4,8,13,12 };
	auto res1 = ::find(vec.begin(), vec.end(), 6);
	auto res2 = ::find(lis.begin(), lis.end(), 8);
	auto res3 = ::find(lis.begin(), lis.end(), 11);
	return 0;
}