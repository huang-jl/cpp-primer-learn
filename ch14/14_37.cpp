#include<vector>
#include<algorithm>
#include<iostream>

using std::vector;

class ifEqual
{
public:
	ifEqual(int v = 0) :i(v) {}
	bool operator()(int a) { return a == i; }
private:
	int i;
};

int main()
{
	vector<int>vec = {1,2,3,4,5,4,3,2,1,2,3,4,10,8,4,1};
	std::replace_if(vec.begin(), vec.end(), ifEqual(4), 5);	//这里的ifEqual是一个对象
	for (const auto& v : vec)
		std::cout << v << " ";
	std::cout << std::endl;
}