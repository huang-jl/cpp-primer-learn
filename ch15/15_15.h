#pragma once
#include"15_3.h"

class Disc_quote:public Quote
{
public:
	Disc_quote() :discount(0.0), quantity(0) {}
	Disc_quote(const string&s, double sale_price, size_t number, double disc) :
		Quote(s, sale_price), quantity(number), discount(disc) {}

	virtual double netPrice(size_t) = 0;
protected:
	double discount;
	size_t quantity;
};

class Bulk_quote :public Disc_quote
{
public:
	Bulk_quote() :Disc_quote() {}
	Bulk_quote(const string&s, double sale_price, size_t number, double disc) :
		Disc_quote(s, sale_price, number, disc) {}

	double netPrice(size_t)override;
};

double Bulk_quote::netPrice(size_t n)
{
	return n * price*(n > quantity ? (1 - discount) : 1);
}