#pragma once
#include<iostream>

class DebugDelete
{
public:
	template<typename Dynamic>
	void operator()(Dynamic* p) { std::cout << "ɾ���ڴ�" << std::endl; delete p; }
};