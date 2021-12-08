#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		const std::string		target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm(const std::string &target);
		virtual ~RobotomyRequestForm();

		std::string			getTarget() const;
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
		void				execute(Bureaucrat const &executor) const;
};

std::ostream	 &operator<<(std::ostream &out, const RobotomyRequestForm &other);

#endif
