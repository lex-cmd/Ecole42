#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Form	*Intern::makeForm(const std::string &name, const std::string &target)
{
	int i(-1);

	std::string	forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	while (++i < 3)
	{
		if (name.compare(forms[i]))
			break;
	}
	
	switch (i)
	{
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "форма не обнаружена";
			break;
	}
	std::cout << "форма не обнаружена";
	return (NULL);
}
