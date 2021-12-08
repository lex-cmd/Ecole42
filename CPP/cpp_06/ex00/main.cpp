#include "Convert.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			Convert pop(argv[1]);
		}
		catch (const std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
		return (0);
	}
	std::cout << "wrong argument!!!" << std::endl;
	return (1);
}
