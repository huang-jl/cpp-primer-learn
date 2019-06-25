#pragma once
#include<utility>

template<typename T,typename F,typename S>
void flip(T func, F&& first, S&& second)
{
	func(std::forward<S>(second), std::forward<F>(first));
	//func(second, first);
}