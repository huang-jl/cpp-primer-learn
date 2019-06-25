#include"16_22.h"

int main()
{
	{
		TextQuery text("story_15.txt");
		QueryResult res = text.query("Alice");
		print_query(res);
	}
		_CrtDumpMemoryLeaks();//16_22.cpp(37)中的static变量会被报告有内存泄漏
	return 0;
}