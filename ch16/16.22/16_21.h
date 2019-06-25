#pragma once
#include<iostream>

class DebugDelete
{
public:
	template<typename Dynamic>
	void operator()(Dynamic* p) { std::cout << "É¾³ýÄÚ´æ" << std::endl; delete p; }
};