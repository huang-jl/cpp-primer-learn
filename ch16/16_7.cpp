template<typename T,unsigned N>
constexpr unsigned size_f(const T(&arr)[N])
{
	return N;
}