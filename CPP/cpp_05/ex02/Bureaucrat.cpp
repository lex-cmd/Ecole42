#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: Grade слишком высокий";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: Grade слишком низкий";
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat() : name("Heimerdinger"), grade(1)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

const std::string	&Bureaucrat::getName() const
{
	return (name);
}

int 		Bureaucrat::getGrade() const
{
	return (grade);
}

void		Bureaucrat::inGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void		Bureaucrat::deGrade()
{
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (out);
}

Bureaucrat	 &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->grade = other.grade;
	return (*this);
}

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}

void 	Bureaucrat::executeForm(Form const &form) const
{
	if (this->getGrade() > form.getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	if (!form.getSign())
		throw Form::FormSignedFalseException();
	form.execute(*this);
}