#pragma once
#include"15_3.h"
class Bulk_quote:public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string book, double sale_price, size_t min_c, double disc) :
		Quote(book, sale_price), min_count(min_c), discount(disc) {}
	double netPrice(size_t)const override;

	//15.11
	void debug()override;

private:
	size_t min_count=0;
	double discount=0.0;
};

double Bulk_quote::netPrice(size_t n)const
{
	return (n > min_count) ? (n*(1 - discount)*price) : (n*price);
}

void Bulk_quote::debug()
{
	std::cout << "booNo=" << getIsbn() << " # price=" << price
		<< "# min_count=" << min_count << " # discount=" << discount << "\n";
}