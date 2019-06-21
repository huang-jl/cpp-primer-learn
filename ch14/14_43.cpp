#include<functional>
#include<vector>
#include<iostream>
#include<algorithm>

using std::vector;
using std::modulus;

int main()
{
	vector<int>vec{ 2,3,4,5 };
	for (int i = 0; std::cout<<"请输入你想判断的整数，q退出"<<std::endl,std::cin >> i;)
	{
		if (vec.size()-std::count_if(vec.begin(), vec.end(), std::bind(modulus<int>(), i, std::placeholders::_1)))
			std::cout << "是" << std::endl;
		else
			std::cout << "否" << std::endl;
	}
	return 0;
}