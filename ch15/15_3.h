#pragma once
#include<string>
#include<iostream>

using std::string;
class Quote
{
public:
	Quote() :price(0.0) {}
	Quote(const string&book, double sale_price) :bookNo(book), price(sale_price) {}
	virtual ~Quote() = default;

	const string getIsbn() const { return bookNo; }
	virtual double netPrice(size_t n)const { return n * price; };

	//15.11
	virtual void debug();

protected:
	double price;
private:
	string bookNo;
};

double print_total(std::ostream&os,const Quote&book,size_t n)
{
	double res = book.netPrice(n);
	os << "ISBN:" << book.getIsbn() << " # sold:" << n << " total due:" << res << std::endl;
	return res;
}

void Quote::debug() 
{
	std::cout << "booNo=" << bookNo << " # price=" << price << "\n";
}