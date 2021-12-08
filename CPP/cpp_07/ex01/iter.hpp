#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T>
void	iter(T &a, int size, void (*func)(T &elem));

#endif
