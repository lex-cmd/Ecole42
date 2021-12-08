#include "phonebook.hpp"

PhoneBookClass::PhoneBookClass()
{
	page = 0;
	all_pages = 0;
}

PhoneBookClass::~PhoneBookClass()
{
	
}

void	PhoneBookClass::print_one(int	num)
{
	std::cout.setf(std::ios::right);
	std::cout.width(10);
	std::cout << num;
}

void	PhoneBookClass::print_one(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		std::cout.setf(std::ios::right);
		std::cout.width(10);
		std::cout << str;
	}
}

void	PhoneBookClass::addData()
{
	std::string	str;

	if (page > 7)
		page = 0;
	std::cout << "Write first name: ";
	std::getline(std::cin, str);
	contacts[page].setFirst_name(str);

	std::cout << "Write last name: ";
	std::getline(std::cin, str);
	contacts[page].setLast_name(str);

	std::cout << "Write nickname: ";
	std::getline(std::cin, str);
	contacts[page].setNickname(str);

	std::cout << "Write phone number: ";
	std::getline(std::cin, str);
	contacts[page].setPhonenumber(str);

	std::cout << "Write darkest secret: ";
	std::getline(std::cin, str);
	contacts[page].setDarkest_secret(str);

	contacts[page].setIndex(page + 1);
	all_pages++;
	page++;
}

void	PhoneBookClass::searchData()
{
	int	print;

	if (all_pages > 7)
		all_pages = 8;
	print = -1;
	while (++print < all_pages)
	{
		print_one(contacts[print].getIndex());
		std::cout << "|";
		print_one(contacts[print].getFirst_name());
		std::cout << "|";
		print_one(contacts[print].getLast_name());
		std::cout << "|";
		print_one(contacts[print].getNickname());
		std::cout << "|";
		std::cout << std::endl;
	}

	std::string str;
	print = -1;
	std::cout << "Number of contact: ";
	std::getline(std::cin, str);
	while (++print < all_pages)
	{
		if (atoi(str.c_str()) == contacts[print].getIndex())
			std::cout << contacts[print] << std::endl;
			return ;
	}
	std::cout << "Index not found: " << str << std::endl;
}
