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

	void		setIndex(int newindex);
	int			getIndex();

	void		setFirst_name(std::string newstr);
	std::string	getFirst_name();

	void		setLast_name(std::string newstr);
	std::string	getLast_name();

	void		setNickname(std::string newstr);
	std::string	getNickname();

	void		setPhonenumber(std::string newstr);
	std::string	getPhonenumber();

	void		setDarkest_secret(std::string newstr);
	std::string	getDarkest_secret();
};

std::ostream	&operator<<(std::ostream &out, const ContactClass &other);

#endif
