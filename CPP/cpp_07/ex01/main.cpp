#include "iter.hpp"

template<typename T>
void	print(T &elem)
{
	std::cout << elem << " ";
}

template<typename T>
void	iter(T *a, int size, void (*func)(T &elem))
{
	for (int i = 0; i < size; i++)
		func(a[i]);
	std::cout << std::endl;
}

int main()
{
	int		size = 9;
	int		array[size];
	double	arraydo[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = i + 1;
		arraydo[i] = i + 0.5;
	}
	iter(array, size, print);
	iter(arraydo, size, print);

	size = 14;
	std::string str("Hello World!!!");
	char		arraych[size];
	for (int i = 0; i < size; i++)
	{
		arraych[i] = str[i];
	}
	iter(arraych, size, print);
}
