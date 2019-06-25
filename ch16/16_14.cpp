#include<iostream>
using std::ostream; using std::istream;

template<unsigned high, unsigned wide>class Screen;
template<unsigned high, unsigned wide>
ostream&operator<<(ostream&, const Screen<high, wide>&);
template<unsigned high, unsigned wide>
istream&operator>>(istream&, Screen<high, wide>&);

template<unsigned high,unsigned wide>
class Screen
{
	friend ostream& operator<< <high, wide>(ostream&, const Screen&);
	friend istream& operator>> <high, wide>(istream&, Screen&);
public:
	Screen() :height(high), width(wide) {}
private:
	unsigned height;
	unsigned width;
};

template<unsigned high, unsigned wide>
ostream&operator<<(ostream&os, const Screen<high, wide>&s)
{
	os << "height=" << s.height << "width=" << s.width;
	return os;
}

template<unsigned high, unsigned wide>
istream&operator>>(istream&is, Screen<high, wide>&s)
{
	is >> s.height >> s.width;
	return is;
}

int main()
{
	Screen<10, 5>s;
	std::cout << s << "\n";
	std::cin >> s;
	std::cout << s << "\n";

	return 0;
}