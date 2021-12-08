#include "phonebook.hpp"

int	main(void)
{
	PhoneBookClass		book;
	std::string			str;

	std::cout << "Write command: ";
	while (std::getline(std::cin, str))
	{
		if (str == "EXIT")
			return (0);
		if ((str == "ADD"))
			book.addData();
		else if (str == "SEARCH")
			book.searchData();
		std::cout << "Write command: ";
	}
	std::cout << std::endl;
	return 0;
}
