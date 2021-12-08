#include "Form.hpp"

Form::Form() : name("Hextech declaration"), grade(11), sign(false)
{
}

Form::Form(const Form &other) : name(other.name), grade(other.grade), sign(other.sign)
{
}

Form::Form(const std::string name, const int grade) : name(name), grade(grade), sign(false)
{
}

Form::~Form()
{
}

void				Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->grade)
		throw Bureaucrat::GradeTooLowException();
	this->sign = true;
}

const std::string	&Form::getName() const
{
	return (name);
}

const int			&Form::getGrade() const
{
	return (grade);
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
