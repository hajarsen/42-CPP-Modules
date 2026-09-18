#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
template <typename T>
void iter(T *array,const size_t length, void (*function)(T &))
{
	if (!array || !length || !function)
		return ;
	for (size_t i = 0; i < length; ++i)
		function(array[i]);
}
template <typename T>
void iter(const T *array,const size_t length, void (*function)(const T &))
{
	if(!array || !length || !function)
		return;
	for (size_t i = 0; i < length; ++i)
		function(array[i]);
}
#endif
