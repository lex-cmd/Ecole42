#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <class T>
typename T::iterator	easyfind(T &found, int &num)
{
	typename T::iterator	it;

	try
	{
		it = std::find(found.begin(), found.end(), num);
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return (it);
}


#endif
