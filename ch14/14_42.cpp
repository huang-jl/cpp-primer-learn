#include<functional>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using std::vector;
using std::cout; using std::endl;
using std::string;

int main()
{
	vector<int>vec = {516,45869,8465,516,51,3512};
	vector<string>text = {"pooh","pooh","good"};
	std::equal_to<int>et;
	cout << "值大于1024的有" <<
		std::count_if(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 1024));
	cout << "第一个不等于pooh的字符串是" <<
		*std::find_if_not(text.begin(), text.end(), std::bind(std::equal_to<string>(), std::placeholders::_1, "pooh")) << endl;
	std::transform(vec.begin(), vec.end(),vec.begin(),std::bind(std::multiplies<int>(), std::placeholders::_1, 2));
	return 0;
}