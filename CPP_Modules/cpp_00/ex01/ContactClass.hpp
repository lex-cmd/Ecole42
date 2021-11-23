#ifndef CONTACTCLASS_HPP
# define CONTACTCLASS_HPP

#include "phonebook.hpp"

class ContactClass
{
	private:

	int			index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	public:

	void		SetIndex(int newindex);
	int			GetIndex();

	void		SetFirst_name(std::string newstr);
	std::string	GetFirst_name();

	void		SetLast_name(std::string newstr);
	std::string	GetLast_name();

	void		SetNickname(std::string newstr);
	std::string	GetNickname();

	void		SetPhonenumber(std::string newstr);
	std::string	GetPhonenumber();

	void		SetDarkest_secret(std::string newstr);
	std::string	GetDarkest_secret();

	void	print_full_one();
};

#endif
