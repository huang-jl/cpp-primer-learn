#include"14_23.h"
StrVec::StrVec(const StrVec&sv)
{
	auto res = check_n_copy(sv.begin(), sv.end());
	element = res.first;
	first_free = res.second;
	cap = res.second;
}
StrVec::StrVec(std::initializer_list<const string>l1)
{
	auto res = check_n_copy(l1.begin(), l1.end());
	element = res.first;
	first_free = res.second;
	cap = res.second;
}

StrVec::~StrVec()
{
	deallocate();
}

StrVec& StrVec::operator=(const StrVec&rhs)
{
	std::pair<string*, string*>res = check_n_copy(rhs.begin(), rhs.end());
	deallocate();
	element = res.first;
	first_free = res.second;
	cap = res.second;
	return *this;
}

void StrVec::push_back(const string&s)
{
	check_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::deallocate()
{
	if (!element)
		return;
	for (auto p = first_free; p != element;)
		alloc.destroy(--p);
	alloc.deallocate(element, cap - element);
}

std::pair<string*, string*> StrVec::check_n_copy(const string*b, const string*e)
{
	auto ele = alloc.allocate(e - b);
	auto end = std::uninitialized_copy(b, e, ele);
	return { ele,end };
}

void StrVec::reallocate()
{
	size_t size_new = size() ? 2 * size() : 1;
	auto ele = alloc.allocate(size_new), q = ele;
	for (auto p = element; p != first_free; ++p)
		alloc.construct(q++, std::move(*p));
	deallocate();
	first_free = q;
	cap = ele + size_new;
	element = ele;
}

void StrVec::resize(size_t size_new)
{
	resize(size_new, string());
}

void StrVec::reserve(size_t cap_new)
{
	auto b = alloc.allocate(cap_new);
	auto dest = b;
	for (auto p = element; p != first_free;)
		alloc.construct(dest++, std::move(*p++));
	deallocate();
	first_free = dest;
	element = b;
	cap = element + cap_new;
}

void StrVec::resize(size_t size_new, const string&s)
{
	if (size_new <= size())
	{
		for (auto p = first_free; p - element != size_new;)
			alloc.destroy(--p);
		return;
	}
	while (size_new > capacity())
		reserve(size_new);
	auto p = first_free;
	while (p - element != size_new)
		alloc.construct(p++, s);
	first_free = p;
}

//13.49
StrVec::StrVec(StrVec&&rvalue_r) :element(rvalue_r.element), first_free(rvalue_r.first_free), cap(rvalue_r.cap)
{
	rvalue_r.element = rvalue_r.first_free = rvalue_r.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&&rvalue_r)
{
	if (this != &rvalue_r)
	{
		deallocate();
		element = rvalue_r.element;
		first_free = rvalue_r.first_free;
		cap = rvalue_r.cap;
		rvalue_r.element = rvalue_r.first_free = rvalue_r.cap = nullptr;
	}
	return *this;
}

StrVec& StrVec::operator=(std::initializer_list<string>l)
{
	auto res = check_n_copy(l.begin(), l.end());
	deallocate();
	element = res.first;
	first_free = cap = res.second;
	return *this;
}