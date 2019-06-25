#include"16_63.h"
#include<iostream>
#include<string>

using std::cout;using std::endl;
using std::string;

int main()
{
	vector<int>v_i = { 1,2,3,4,5,6,7,8,9,8,7 };
	vector<double>v_d = { 1.2,1.3,1.1,1.2,1.2,2.5 };
	vector<string>v_s = { "go","god","go","good","god","go" };
	cout << "times of 8 in v_i=" << my_count(v_i, 8) << endl;
	cout << "times of 1.2 in v_d=" << my_count(v_d, 1.2) << endl;
	cout << "times of go in v_s=" << my_count(v_s, string("go")) << endl;
	

	vector<const char*>v_c = { "go","god","go","good","god","go" };
	cout << "times of go in v_c=" << my_count(v_c,(const char*)"go") << endl;
	return 0;
}