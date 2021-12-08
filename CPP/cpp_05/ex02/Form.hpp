#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		const int			grade;
		const int			execGrade;
		bool				sign;
	public:
		Form();
		Form(const Form &other);
		Form(const std::string, const int grade, const int execGrade);
		~Form();

		const std::string	&getName() const;
		const int			&getGrade() const;
		const int			&getExecGrade() const;
		bool				getSign() const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const &bureaucrat) const = 0;
		class 				FormSignedTrueException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class FormSignedFalseException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream	 &operator<<(std::ostream &out, const Form &other);

#endif