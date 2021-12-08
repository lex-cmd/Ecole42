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

std::ostream	&operator<<(std::ostream &out, const ContactClass &other)
{
	out.setf(std::ios::right);
	out << "index:" << "\t\t" << getIndex() << std::endl;
	out << "first_name:" << "\t" << other.getFirst_name() << std::endl;
	out << "last_name:" << "\t" << other.getLast_name() << std::endl;
	out << "nickname:" << "\t" << other.getNickname() << std::endl;
	out << "phonenumber:" << "\t" << other.getPhone_number() << std::endl;
	out << "darkest_secret:" << "\t" << other.getDarkest_secret();
	return (out);
}
