#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		const int			grade;
		bool				sign;
	public:
		Form();
		Form(const Form &other);
		Form(const std::string, const int grade);
		~Form();

		void				beSigned(const Bureaucrat &bureaucrat);
		const std::string	&getName() const;
		const int			&getGrade() const;
		bool				getSign() const;
};

std::ostream	 &operator<<(std::ostream &out, const Form &other);

#endif