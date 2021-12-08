#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <cstdlib>


class Span
{
	private:
		int	*store;
		int	size;
		int	it;

	public:
		Span();
		Span(int size);
		Span(const Span &other);
		~Span();

		int		getSize() const;
		void	addNumber(int newnum);
		int		shortestSpan();
		int		longestSpan();
		int		max();
		int		min();
		void	printAll();
		Span	&operator=(const Span &other);
		class OutOfRangeException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif