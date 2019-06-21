#include"15_26.h"
#include"15_27.h"
#include<memory>
#include<vector>

using std::shared_ptr;
using std::vector;

int main()
{
	//15.28=9090
	double total = 0.0;
	vector<Quote>bucket;
	for (unsigned i = 1; i != 10; ++i)
		bucket.push_back(Bulk_quote("sss", i * 10.1, 10, 0.3));

	for (const auto& p : bucket)
		total += p.netPrice(20);
	cout << "15.28=" << total << endl;

	//15.29=6363
	vector<shared_ptr<Quote>>bucket_p;
	for (unsigned i = 1; i != 10; ++i)
		bucket_p.push_back(std::make_shared<Bulk_quote>(Bulk_quote("sss", i * 10.1, 10, 0.3)));

	total = 0.0;
	for (const auto& p : bucket_p)
		total += p->netPrice(20);
	cout << "15.29=" << total << endl;

	return 0;
}