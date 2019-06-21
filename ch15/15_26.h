#pragma once
#include<string>
#include<iostream>

using std::string;
using std::cout; using std::endl;

/*
*首先是类Quote
*/
class Quote
{
public:
	Quote() :price(0.0) { cout << "Quote::Quote()\n"; }
	Quote(const string&book, double sale_price) :bookNo(book), price(sale_price)
	{
		cout << "Quote::Quote(const string&, double)\n";
	}
	virtual ~Quote() { cout << "Quote::~Quote()\n"; }
	Quote(const Quote&rhs) :price(rhs.price), bookNo(rhs.bookNo) { cout << "Quote::Quote(const Quote&)\n"; }
	Quote(Quote&&rhs)noexcept :price(std::move(rhs.price)), bookNo(std::move(rhs.bookNo)) { cout << "Quote::Quote(Quote&&)\n"; }
	Quote& operator=(Quote&&rhs)noexcept;
	Quote& operator=(const Quote&rhs)noexcept;


	const string getIsbn() const { return bookNo; }
	virtual double netPrice(size_t n)const { return n * price; };

	//15.11
	virtual void debug();

	//15.30
	virtual Quote* alloc()const &;
	virtual Quote*alloc() && ;
protected:
	double price;
private:
	string bookNo;
};

double print_total(std::ostream&os, const Quote&book, size_t n)
{
	double res = book.netPrice(n);
	os << "ISBN:" << book.getIsbn() << " # sold:" << n << " total due:" << res << std::endl;
	return res;
}

void Quote::debug()
{
	std::cout << "booNo=" << bookNo << " # price=" << price << "\n";
}

Quote& Quote::operator=(Quote&&rhs)noexcept
{
	if (this != &rhs)
	{
		cout << "Quote::operator=(Quote&&)\n";
		price = std::move(rhs.price);
		bookNo = std::move(rhs.bookNo);
	}
	return *this;
}

Quote& Quote::operator=(const Quote&rhs)noexcept
{
	if (this != &rhs)
	{
		cout << "Quote::operator=(const Quote&)\n";
		price = rhs.price;
		bookNo = rhs.bookNo;
	}
	return *this;
}

Quote* Quote::alloc()const &
{
	return new Quote(*this);
}

Quote* Quote::alloc() &&
{
	return new Quote(std::move(*this));
}

/*
*类Bulk_quote是类似的
*就不做修改了
*/

