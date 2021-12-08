#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <deque>
# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	MutantStack(): std::stack<T>(){}
	MutantStack(const MutantStack &other): std::stack<T>(other){}
	virtual ~MutantStack(){}

	MutantStack &operator=(const MutantStack &other)
	{
		std::stack<T>::operator=(other);
		return (*this);
	}

	iterator	begin()
	{
		return (std::stack<T>::c.begin());
	}

	iterator	end()
	{
		return (std::stack<T>::c.end());
	}
	
	reverse_iterator	rbegin()
	{
		return (std::stack<T>::c.rbegin());
	}

	reverse_iterator	rend()
	{
		return (std::stack<T>::c.rend());
	}

};

#endif