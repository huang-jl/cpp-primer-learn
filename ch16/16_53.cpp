#include<iostream>
using std::ostream;

template<typename T>
ostream& print(ostream&os, const T&t)
{
	os << t << std::endl;
	return os;
}

template<typename T,typename ...Args>
ostream& print(ostream&os, const T&t, const Args&...rest)
{
	os << t << ", ";
	return print(os, rest...);
}


int main()
{
	print(std::cout, 42);
	print(std::cout, 42, "was");
	print(std::cout, 42, "good", "nice work", 'a', 38291);

	return 0;
}