#include<algorithm>
#include<string>
#include<fstream>
#include<vector>
#include<iostream>
#include<sstream>
#include<iterator>

using std::string;
using std::vector;

class isSameLength
{
public:
	isSameLength(size_t l) :length(l) {}
	bool operator()(const string&str)
	{
		return str.size() == length;
	}
private:
	size_t length;
};

int main()
{
	std::ifstream ifs("input.txt");
	vector<string>vec;
	for (string str; std::getline(ifs,str);)
	{
		string text,word;
		auto p = std::back_inserter(text);
		std::remove_copy_if(str.begin(), str.end(), p, ispunct);
		std::istringstream iss(text);
		while(iss >> word)
			vec.push_back(word);
	}
	for (int i = 1; i <= 10; ++i)
		std::cout << "长度等于" << i << "的单词个数为:" 
		<< std::count_if(vec.begin(), vec.end(), isSameLength(i)) << std::endl;
	return 0;
}