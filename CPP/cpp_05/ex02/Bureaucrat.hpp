#ifndef BUREAUCRAT
# define BUREAUCRAT

# include <string>
# include <iostream>
# include <cstdlib>

class Form;
# include <Form.hpp>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		virtual	~Bureaucrat();

		const std::string			&getName() const;
		int 						getGrade() const;
		void						inGrade();
		void						deGrade();

		void						signForm(Form &form);
		void 			 			executeForm(Form const & form) const;
		Bureaucrat	 				&operator=(const Bureaucrat &other);

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream	 &operator<<(std::ostream &out, const Bureaucrat &other);

#endif