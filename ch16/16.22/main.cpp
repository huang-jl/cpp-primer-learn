#include"16_22.h"

int main()
{
	{
		TextQuery text("story_15.txt");
		QueryResult res = text.query("Alice");
		print_query(res);
	}
		_CrtDumpMemoryLeaks();//16_22.cpp(37)�е�static�����ᱻ�������ڴ�й©
	return 0;
}