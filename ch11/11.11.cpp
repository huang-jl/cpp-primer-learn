#include<set>

using namespace std;
class Sales_data;
bool compareIsbn(const Sales_data&, const Sales_data&);
multiset<Sales_data, bool(*)(const Sales_data&, const Sales_data&)>bookstore(compareIsbn);