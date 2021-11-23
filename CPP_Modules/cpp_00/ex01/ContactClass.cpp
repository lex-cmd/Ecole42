#include "phonebook.hpp"

/* Setter Getter */

/*Index*/

void	ContactClass::SetIndex(int newindex)
{
	index = newindex;
}

int		ContactClass::GetIndex()
{
	return (index);
}

/*first_name*/

void	ContactClass::SetFirst_name(std::string newstr)
{
	first_name = newstr;
}

std::string		ContactClass::GetFirst_name()
{
	return (first_name);
}

/*last_name*/

void	ContactClass::SetLast_name(std::string newstr)
{
	last_name = newstr;
}

std::string		ContactClass::GetLast_name()
{
	return (last_name);
}

/*nickname*/

void	ContactClass::SetNickname(std::string newstr)
{
	nickname = newstr;
}

std::string		ContactClass::GetNickname()
{
	return (nickname);
}

/*phonenumber*/

void	ContactClass::SetPhonenumber(std::string newstr)
{
	phone_number = newstr;
}

std::string		ContactClass::GetPhonenumber()
{
	return (phone_number);
}

/*darkest_secret*/

void	ContactClass::SetDarkest_secret(std::string newstr)
{
	darkest_secret = newstr;
}

std::string		ContactClass::GetDarkest_secret()
{
	return (darkest_secret);
}

/*Print Info*/

void	ContactClass::print_full_one()
{
	std::cout.setf(std::ios::right);
	std::cout << "index:" << "\t\t" << index << std::endl;
	std::cout << "first_name:" << "\t" << first_name << std::endl;
	std::cout << "last_name:" << "\t" << last_name << std::endl;
	std::cout << "nickname:" << "\t" << nickname << std::endl;
	std::cout << "phonenumber:" << "\t" << phone_number << std::endl;
	std::cout << "darkest_secret:" << "\t" << darkest_secret << std::endl;
}
