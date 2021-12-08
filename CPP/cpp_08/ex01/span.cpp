#include "span.hpp"

Span::Span()
{

}

Span::Span(int size)
{
	store = new int(size);
	this->size = size;
	it = 0;
	for (int i = 0; i < size; i++)
		store[i] = 0;
}

Span::~Span()
{

}

Span::Span(const Span &other)
{
	this->size = other.size;
	this->it = other.it;
	this->store = 0;
	if (other.store)
	{
		this->store = new int(other.size);
		for (int i = 0; i < other.size; i++)
			this->store[i] = other.store[i];
	}
}

Span	&Span::operator=(const Span &other)
{
	if (&other == this)
		return (*this);
	this->size = other.size;
	this->it = other.it;
	if (this->store)
		delete this->store;
	this->store = 0;
	if (other.store)
	{
		this->store = new int(other.size);
		for (int i = 0; i < other.size; i++)
			this->store[i] = other.store[i];
	}
	return (*this);
}

const char* Span::OutOfRangeException::what() const throw()
{
	return ("OutOfRangeException: out of range array");
}

int		Span::getSize() const
{
	return (this->size);
}

void	Span::addNumber(int newnum)
{
	if (this->it >= this->size)
		throw Span::OutOfRangeException();
	store[it] = newnum;
	this->it++;
}

int		Span::max()
{
	int max = INT_MIN;

	for (int i = 0; i < this->size; i++)
	{
		if (max < store[i])
			max = store[i];
	}
	return (max);
}

int		Span::min()
{
	int min = INT_MAX;

	for (int i = 0; i < this->size; i++)
	{
		if (min > store[i])
			min = store[i];
	}
	return (min);
}

int		Span::shortestSpan()
{
   int diff = INT_MAX;

   for (int i = 0; i < size - 1; i++)
      for (int j = i + 1; j < size; j++)
          if (abs(store[i] - store[j]) < diff)
                diff = abs(store[i] - store[j]);
	return (diff);
}

int		Span::longestSpan()
{
	return (abs(max() - min()));
}

void	Span::printAll()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << store[i] << " ";
	}
	std::cout << std::endl;
}
