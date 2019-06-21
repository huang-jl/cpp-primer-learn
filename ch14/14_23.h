#pragma once
#include<string>
#include<utility>
#include<memory>
#include<algorithm>

using std::string; using std::allocator;

class StrVec
{
public:
	StrVec() :element(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	//13.49
	StrVec(StrVec&&);
	StrVec& operator= (StrVec&&);
	//13.49
	StrVec& operator=(std::initializer_list<string>);

	StrVec(std::initializer_list<const string>);
	~StrVec();


	void push_back(const string&);
	string* begin() const { return element; };
	string* end()const { return first_free; };
	size_t size()const { return first_free - element; };
	size_t capacity()const { return cap - element; };
	void resize(size_t);
	void resize(size_t, const string&);
	void reserve(size_t cap_new);
private:

	void check_n_alloc() { if (size() == capacity()) reallocate(); };
	std::pair<string*, string*> check_n_copy(const string*, const string*);
	void reallocate();
	void deallocate();

	allocator<string>alloc;
	string* element;
	string* first_free;
	string* cap;
};