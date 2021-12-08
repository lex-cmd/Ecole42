#include "span.hpp"

int main()
{
	srand(time(NULL));
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp_ten = Span(10000);
	sp_ten.addNumber(0);
	for (int i = 0; i < 9999; i++)
		sp_ten.addNumber(60 + rand() % 2000000);
	std::cout << sp_ten.shortestSpan() << std::endl;
	std::cout << sp_ten.longestSpan() << std::endl;
}
