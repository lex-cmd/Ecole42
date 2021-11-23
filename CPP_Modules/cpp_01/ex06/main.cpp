#include "Karen.hpp"

static	int	filter(std::string level)
{
	std::string	all_levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(all_levels[i]) == 0)
			return (i);
	}
	return (5);
}

int	main(int argc, char **argv)
{
	Karen	karen;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	switch (filter(argv[1]))
	{
		case (0):
			karen.complain("DEBUG");
			break;
		case (1):
			karen.complain("INFO");
			break;
		case (2):
			karen.complain("WARNING");
			break;
		case (3):
			karen.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return(1);
	}
	return(0);
}
