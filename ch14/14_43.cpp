#include<functional>
#include<vector>
#include<iostream>
#include<algorithm>

using std::vector;
using std::modulus;

int main()
{
	vector<int>vec{ 2,3,4,5 };
	for (int i = 0; std::cout<<"�����������жϵ�������q�˳�"<<std::endl,std::cin >> i;)
	{
		if (vec.size()-std::count_if(vec.begin(), vec.end(), std::bind(modulus<int>(), i, std::placeholders::_1)))
			std::cout << "��" << std::endl;
		else
			std::cout << "��" << std::endl;
	}
	return 0;
}