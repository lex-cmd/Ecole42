#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string		target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();

		std::string				getTarget() const;
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		void					execute(Bureaucrat const &executor) const;
};

std::ostream	 &operator<<(std::ostream &out, const PresidentialPardonForm &other);

#endif
