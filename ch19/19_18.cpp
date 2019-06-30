#include<vector>
#include<functional>
#include<algorithm>
#include<iostream>
#include<string>

using std::vector;
using std::string;
using std::cout; using std::endl;

int main()
{
	vector<string>svec = { "","good","boy","","not","" };
	std::function<bool(const string&)>f(&string::empty);
	cout << std::count_if(svec.begin(), svec.end(), f) << endl;

	cout << std::count_if(svec.begin(), svec.end(), std::mem_fn(&string::empty)) << endl;

	cout << std::count_if(svec.begin(), svec.end(), std::bind(&string::empty, std::placeholders::_1));

	return 0;
}
