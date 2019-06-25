#include"16_47.h"
#include<iostream>

using std::cout; using std::endl;
void compare(int a, int b) { cout << static_cast<bool>(a <= b) << endl; }
void compare_1(int&a, int&b) { cout << static_cast<bool>(a <= ++b) << endl; }
void compare_2(int&&a, int&&b) { cout << static_cast<bool>(a <= b) << endl; }
int main()
{
	int i = 5, j = 6;
	flip(compare, i, j);
	flip(compare_1, i, j);
	flip(compare_2, 5, 6);
	return 0;
}