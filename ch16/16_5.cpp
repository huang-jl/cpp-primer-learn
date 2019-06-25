#include<iostream>
using std::cout; using std::endl;

template<typename T,unsigned M>
void print(const T(&arr)[M])
{
	for (const auto& ele : arr)
		cout << ele << endl;
}

int main()
{
	int arr[10]{ 1,2,3,4,5,6,7,8,9,10 };
	print(arr);

	return 0;
}