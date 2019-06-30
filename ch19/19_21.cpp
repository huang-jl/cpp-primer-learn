#include"19_21.h"

void Token::UnionCopy(const Token&t)
{
	switch ((t.tok))
	{
	case INT:
		ival = t.ival;
		break;
	case CHAR:
		cval = t.cval;
		break;
	case DOUBLE:
		dval = t.dval;
		break;
	case STR:
		new(&sval)string(t.sval);
		break;
	default:
		break;
	}
}

void Token::UnionMove(Token&&t)
{
	switch ((t.tok))
	{
	case INT:
		ival = std::move(t.ival);
		break;
	case CHAR:
		cval = std::move(t.cval);
		break;
	case DOUBLE:
		dval = std::move(t.dval);
		break;
	case STR:
		new(&sval)string(std::move(t.sval));
		break;
	default:
		break;
	}
}

Token& Token::operator=(const Token&t)
{
	if (tok == STR && t.tok != STR)
		sval.~string();
	/********************************/
	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else
		UnionCopy(t);
	tok = t.tok;
	return *this;
}

Token& Token::operator=(const int i)
{
	if (tok == STR)
		sval.~string();
	tok = INT;
	ival = i;
	return *this;
}

Token& Token::operator= (const char ch)
{
	if(tok==STR)
		sval.~string();
	cval = ch;
	tok = CHAR;
	return *this;
}

Token& Token::operator=(const double d)
{
	if (tok == STR)
		sval.~string();
	dval = d;
	tok = DOUBLE;
	return *this;
}

Token& Token::operator=(const string&s)
{
	if (tok == STR)
		sval = s;
	else
		new(&sval)string(s);
	tok = STR;
	return *this;
}

Token::Token(Token&&t):tok(std::move(t.tok))
{
	UnionMove(std::move(t));
}

Token& Token::operator=(Token&&t)
{
	if (tok == STR && t.tok != STR)
		sval.~string();
	if (tok == STR && t.tok == STR)
		sval = std::move(t.sval);
	else
		UnionMove(std::move(t));
	return *this;
}