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
	
	Query_base *p = new AndQuery(Query("hair"),Query("Alice"),"&");
	p = dynamic_cast<AndQuery*>(p);
	if (typeid(*p) == typeid(AndQuery))
		cout << "true" << endl;
	if (typeid(*p) == typeid(Query_base))
		cout << "false" << endl;

	AndQuery and_q(Query("hair"), Query("Alice"), "&");
	Query_base &r = and_q;
	r = dynamic_cast<AndQuery&>(r);
	if (typeid(r) == typeid(AndQuery))
		cout << "true" << endl;
	if (typeid(r) == typeid(Query_base))
		cout << "false" << endl;

	if (typeid(*p) == typeid(r))
		cout << "true" << endl;

	return 0;
}