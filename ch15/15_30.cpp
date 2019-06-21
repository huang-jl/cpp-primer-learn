#include"15_26.h"
#include"15_27.h"
#include<set>
#include<memory>

using std::multiset;
using std::shared_ptr;

bool compare(shared_ptr<Quote>&lhs, shared_ptr<Quote>&rhs)
{
	return lhs->getIsbn() < rhs->getIsbn();
}
class Basket
{
public:
	inline void add_item(const Quote&b);
	inline void add_item(Quote&&);

	double total_receipt(std::ostream&)const;
private:
	multiset<shared_ptr<Quote>, decltype(compare)*>items{ compare };
};

inline void Basket::add_item(const Quote&b)
{
	items.insert(shared_ptr<Quote>(b.alloc()));
}

inline void Basket::add_item(Quote&&b)
{
	items.insert(shared_ptr<Quote>(std::move(b).alloc()));
}

double Basket::total_receipt(std::ostream&os)const
{
	double total = 0.0;
	for (auto b = items.cbegin(); b != items.cend(); b = items.upper_bound(*b))
	{
		total+=print_total(os, **b, items.count(*b));
	}
	return total;
}

int main()
{
	Basket basket;
	for (unsigned i = 0; i != 10; ++i)
		basket.add_item(Bulk_quote("Bible", 20.6, 20, 0.3));

	for (unsigned i = 0; i != 10; ++i)
		basket.add_item(Bulk_quote("C++Primer", 30.9, 5, 0.4));

	for (unsigned i = 0; i != 10; ++i)
		basket.add_item(Quote("CLRS", 40.1));
	cout<<"total="<<basket.total_receipt(cout)<<endl;
	return 0;
}