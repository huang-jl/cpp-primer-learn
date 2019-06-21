#include<iostream>
#include<string>
#include<vector>

class MyReadString
{
public:
	const std::string operator()(std::istream&is = std::cin)
	{
		std::string str;
		if(std::getline(is, str))
			return str;
		else return str;
	}
};

//14_36
int main()
{
	MyReadString mrs;
	std::vector<std::string>vec;
	for (std::string str; (str = mrs())!=std::string(); vec.push_back(str));
	return 0;
}