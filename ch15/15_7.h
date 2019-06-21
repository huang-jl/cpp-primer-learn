#pragma once
#include"15_3.h"

class Limit_quote: public Quote
{
public:
	Limit_quote() = default;
	Limit_quote(const string& book, double sale_price, size_t limit_c, double disc) :
		Quote(book, sale_price), limit_count(limit_c), discount(disc) {}

	double netPrice(size_t)const override;

	//15.11
	void debug()override;
private:
	size_t limit_count = 0;
	double discount = 0.0;
};

double Limit_quote::netPrice(size_t n)const
{
	return (n > limit_count) ? 
		(n - limit_count)*price + limit_count * price*(1 - discount) : n * price*(1 - discount);
}

void Limit_quote::debug()
{
	std::cout << "booNo=" << getIsbn() << " # price=" << price
		<< " # limit_count=" << limit_count << " # discount=" << discount << "\n";
}