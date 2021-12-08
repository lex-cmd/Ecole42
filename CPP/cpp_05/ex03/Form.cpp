#include "Form.hpp"

Form::Form() : name("Hextech declaration"), grade(7), execGrade(2), sign(false)
{
}

Form::Form(const Form &other) : name(other.name), grade(other.grade), execGrade(other.execGrade), sign(other.sign)
{
	if (other.grade > 250 || other.execGrade > 250)
		throw Bureaucrat::GradeTooLowException();
	if (other.grade < 1 || other.execGrade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Form::Form(const std::string name, const int grade, const int execGrade) : name(name), grade(grade), execGrade(execGrade), sign(false)
{
	if (grade > 250 || execGrade > 250)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1 || execGrade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Form::~Form()
{
}

void				Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > this->grade)
		throw Bureaucrat::GradeTooLowException();
	if (sign)
		throw FormSignedTrueException();
	sign = true;
}

const char* Form::FormSignedTrueException::what() const throw()
{
	return "FormSignedTrueException: Форма уже подписана";
}

const char* Form::FormSignedFalseException::what() const throw()
{
	return "FormSignedFalseException: Форма еще не подписана";
}

const std::string	&Form::getName() const
{
	return (this->name);
}

const int			&Form::getGrade() const
{
	return (this->grade);
}

const int			&Form::getExecGrade() const
{
	return (this->execGrade);
}

bool				Form::getSign() const
{
	return (sign);
}

std::ostream	 &operator<<(std::ostream &out, const Form &other)
{
	out << "Form name " << other.getName() << ", grade " << other.getGrade() << ", status " << other.getSign();
	return (out);
}
