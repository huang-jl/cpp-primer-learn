template<typename T,unsigned M>
T* begin_f(const T(&arr)[M])
{
	return arr[0];
}

template<typename T, unsigned M>
T* end_f(const T(&arr)[M])
{
	return arr[M];
}

