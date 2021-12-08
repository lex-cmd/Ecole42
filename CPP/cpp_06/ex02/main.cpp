#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	Base *new_base;

	std::srand(time(NULL));
	switch (1 + std::rand() % 3)
	{
		case (1):
		{
			new_base = new(A);
			break;
		}
		case (2):
		{
			new_base = new(B);
			break;
		}
		case (3):
		{
			new_base = new(C);
			break;
		}
	}
	return(new_base);
}

void identify(Base* p)
{
	std::cout << *p << std::endl;
}

void identify(Base& p)
{
	std::cout << p << std::endl;
}

int	main()
{
	Base *base = generate();
	Base &base_s = *base;

	identify(base);
	identify(base_s);
}
