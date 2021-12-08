#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("RobotomyRequest", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm()
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor.getName() << " выполнил форму " << this->getName() << std::endl;
	std::cout << "Makes some drilling noises, and tell us that " << getTarget() << " has been robotomized successfully 50% of the time. Otherwise, tell us it’s a failure" << std::endl;
}

std::string		RobotomyRequestForm::getTarget() const
{
	return (target);
}

std::ostream	 &operator<<(std::ostream &out, const RobotomyRequestForm &other)
{
	out << "Form name " << other.getName() << " grade " << other.getGrade() << ", status " << other.getSign() << ", target " << other.getTarget();
	return (out);
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	target = other.target;

	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
}
