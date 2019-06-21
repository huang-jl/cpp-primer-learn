#include<algorithm>

void StrVec::free()
{
	std::for_each(element, first_free, [this](string &str) {alloc.destroy(&str)});
	alloc.deallocate(element, cap - element);
}