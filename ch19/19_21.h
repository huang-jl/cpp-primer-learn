#pragma once
#include<string>
using std::string;

class Token
{
public:
	Token() :tok(INT), ival(0) {}
	Token(const Token&t) :tok(t.tok) { UnionCopy(t); }
	Token(Token&&)noexcept;

	Token& operator=(const Token&);
	Token& operator=(Token&&)noexcept;
	~Token() { if (tok == STR) sval.~string(); }

	Token& operator= (const int);
	Token& operator= (const string&);
	Token& operator= (const double);
	Token& operator=(const char);
private:
	enum
	{
		INT, CHAR, DOUBLE, STR
	}tok;
	union 
	{
		int ival;
		char cval;
		double dval;
		string sval;
	};
	void UnionCopy(const Token&);
	void UnionMove(Token&&);
};