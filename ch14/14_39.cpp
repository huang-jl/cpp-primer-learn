#include<algorithm>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using std::string;
using std::ifstream;
using std::vector;
using std::cout; using std::endl;

class lengthInRange
{
public:
	lengthInRange() :low(0), up(0) {}
	lengthInRange(int L, int U) :low(L), up(U) {}
	bool operator()(const string&s)
	{
		if (low == 0)
			return s.size() > up;
		else
			return (s.size() > low&&s.size() < up);
	}
private:
	size_t low;
	size_t up;
};

int main()
{
	ifstream ifs("input.txt");
	vector<string>text;
	for (string word; ifs >> word; text.push_back(word));
	cout << "长度在1到9之间的单词有" << std::count_if(text.begin(), text.end(), lengthInRange(1, 9)) << endl;
	cout << "长度在10以上的单词有" << std::count_if(text.begin(), text.end(), lengthInRange(0, 10)) << endl;
	return 0;
}