#include"AndQuery.h"
#include"NotQuery.h"
#include"OrQuery.h"
#include"Query_base.h"
#include"WordQuery.h"
#include<iostream>

using std::cout; using std::endl;
int main(int argc, char*argv[])
{
	TextQuery text("story_15.txt");
	Query q1 = Query("hair") | Query("Alice");
	cout << q1 << endl;
	print_query(q1.equl(text));

	q1 = Query("hair")& Query("Alice");
	cout << q1 << endl;
	print_query(q1.equl(text));

	q1 = ~Query("Alice");
	cout << q1 << endl;
	print_query(q1.equl(text));

	q1 = Query("fiery")&Query("bird")| Query("wind");
	cout << q1 << endl;
	print_query(q1.equl(text));
	return 0;
}