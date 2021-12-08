#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat supervisor("Supervisor", 1);
		Bureaucrat francis("Francis", 25);
		std::cout << std::endl;

		std::cout << francis << std::endl;

		Form *pres = new PresidentialPardonForm("Heimerdinger");
		// supervisor.executeForm(*pres);
		supervisor.signForm(*pres);

		std::cout << *pres << std::endl;
		supervisor.executeForm(*pres);

		std::cout << std::endl;
		pres->execute(supervisor);

		std::cout << std::endl;
		// supervisor.executeForm(*hex);
		Form *hex = new RobotomyRequestForm("Hexbot");

		std::cout << std::endl;
		supervisor.signForm(*hex);
		std::cout << *hex << std::endl;
		supervisor.executeForm(*hex);

		std::cout << std::endl;
		hex->execute(supervisor);
		std::cout << std::endl;
	// Form *tree = new ShrubberyCreationForm("Hex Tree");
	// // supervisor.executeForm(*tree);
	// supervisor.signForm(*tree);
	// std::cout << *tree << std::endl;
	// supervisor.executeForm(*tree);
	// tree->execute(supervisor);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}