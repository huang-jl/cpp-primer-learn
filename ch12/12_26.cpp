#include<allocators>
#include<string>
#include<iostream>

using namespace std;

auto storeString(int n)
{
	allocator<string>alloc;
	auto p=alloc.allocate(n);
	string text;
	auto q = p;
	while (q!=p+n&&cin >> text)
		alloc.construct(q++, text);

	const size_t size = q - p;
	
	while (q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, n);

	return size;
}