#ifndef PHONEBOOKCLASS_HPP
# define PHONEBOOKCLASS_HPP

#include "phonebook.hpp"

class PhoneBookClass
{
	private:
		ContactClass	contacts[8];
		int				page;
		int				all_pages;

	public:

		PhoneBookClass();
		~PhoneBookClass();

		void	print_one(int	num);
		void	print_one(std::string str);

		void	addData();
		void	searchData();
	};

#endif
