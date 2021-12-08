#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		const std::string		target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();

		std::string				getTarget() const;
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
		void					execute(Bureaucrat const &executor) const;
};

std::ostream	 &operator<<(std::ostream &out, const ShrubberyCreationForm &other);

#endif
