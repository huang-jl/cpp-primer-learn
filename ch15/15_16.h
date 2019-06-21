#pragma once
#include"15_15.h"

class Limit_quote : public Disc_quote
{
public:
	Limit_quote() = default;
	Limit_quote(const string& book, double sale_price, size_t limit_c, double disc) :
		Disc_quote(book,sale_price,limit_c,disc) {}

	double netPrice(size_t)const override;
};

double Limit_quote::netPrice(size_t n)const
{
	return (n > quantity) ?
		(n - quantity)*price + quantity * price*(1 - discount) : n * price*(1 - discount);
}