#pragma once
#include"15_26.h"

class Disc_quote :public Quote
{
public:
	Disc_quote() :discount(0.0), quantity(0) {}
	Disc_quote(const string&s, double sale_price, size_t number, double disc) :
		Quote(s, sale_price), quantity(number), discount(disc) {}
	Disc_quote(const Disc_quote&rhs) :Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {}
	Disc_quote(Disc_quote&&rhs) :Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), discount(std::move(rhs.discount))
	{}

	Disc_quote&operator=(const Disc_quote&rhs)noexcept;
	Disc_quote&operator=(Disc_quote&&rhs)noexcept;

protected:
	double discount;
	size_t quantity;
};

Disc_quote& Disc_quote::operator=(const Disc_quote&rhs)noexcept
{
	if (this != &rhs)
	{
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
	}
	return *this;
}

Disc_quote& Disc_quote::operator=(Disc_quote&&rhs)noexcept
{
	if (this != &rhs)
	{
		Quote::operator=(std::move(rhs));
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);
	}
	return *this;
}


class Bulk_quote :public Disc_quote
{
public:
	using Disc_quote::Disc_quote;
	Bulk_quote() = default;
	Bulk_quote(const Bulk_quote&rhs) :Disc_quote(rhs) {}
	Bulk_quote(Bulk_quote&&rhs) :Disc_quote(std::move(rhs)) {}

	//其他的操作符和成员还是类似的定义
	//这里省略了
	double netPrice(size_t)const override;

	//15.30
	Bulk_quote* alloc()const & override;
	Bulk_quote* alloc()&& override;

};

double Bulk_quote::netPrice(size_t n)const
{
	return n * price*(n > quantity ? (1 - discount) : 1);
}

Bulk_quote* Bulk_quote::alloc()const &
{
	return new Bulk_quote(*this);
}

Bulk_quote* Bulk_quote::alloc() &&
{
	return new Bulk_quote(std::move(*this));
}