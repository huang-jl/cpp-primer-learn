#include<cstdlib>
#include<stdexcept>
void *operator new(size_t size)
{
	if (void *memory = malloc(size))
		return memory;
	else
		throw std::bad_alloc();
}

void operator delete(void*memory)noexcept
{
	free(memory);
}