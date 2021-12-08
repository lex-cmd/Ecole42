#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat supervisor("Supervisor", 1);
	Bureaucrat francis("Francis", 25);
	std::cout << std::endl << francis << std::endl;

	Form *pres = new PresidentialPardonForm("Heimerdinger");
	supervisor.signForm(*pres);
	std::cout << *pres << std::endl << std::endl;
	supervisor.executeForm(*pres);

	Form *hex = new RobotomyRequestForm("Hexbot");
	supervisor.signForm(*hex);
	std::cout << *hex << std::endl << std::endl;
	supervisor.executeForm(*hex);

	// Form *tree = new ShrubberyCreationForm("Hex Tree");
	// // supervisor.executeForm(*tree);
	// supervisor.signForm(*tree);
	// std::cout << *tree << std::endl;
	// supervisor.executeForm(*tree);
	// tree->execute(supervisor);

	Intern someRandomIntern;
	Form *rrf;

	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	supervisor.signForm(*rrf);
	supervisor.executeForm(*rrf);

	std::cout << std::endl;

	delete pres;
	delete hex;
	// delete tree
	delete rrf;
	return (0);
}