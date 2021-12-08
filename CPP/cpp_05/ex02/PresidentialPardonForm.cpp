#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardon", 25, 5), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " выполнил форму " << this->getName() << std::endl;
	std::cout << "Tells us " << getTarget() << " has been pardoned by " << executor.getName() << std::endl;
}

std::string		PresidentialPardonForm::getTarget() const
{
	return (target);
}

std::ostream	 &operator<<(std::ostream &out, const PresidentialPardonForm &other)
{
	out << "Form name " << other.getName() << " grade " << other.getGrade() << ", status " << other.getSign() << ", target " << other.getTarget();
	return (out);
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	const_cast<std::string&>(target) = const_cast<std::string&>(other.target);

	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
}
