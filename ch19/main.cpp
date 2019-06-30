#include"19_20.h"

int main()
{
	ifstream ifs("input.txt");
	TextQuery text(ifs);
	print(cout, text.query("my"));


	return 0;
}