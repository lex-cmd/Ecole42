#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	francis("Francis", 100);
	std::cout << francis << std::endl;
	francis.inGrade();
	std::cout << francis << std::endl;
	francis.deGrade();
	std::cout << francis << std::endl;

	Form 	form1;

	try
	{
		Bureaucrat jack("Jack", 0);
		std::cout << jack << std::endl;
		jack.signForm(form1);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat jack("Jack", 1000);
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat jack("Jack", 1);
		std::cout << jack << std::endl;
		jack.inGrade();
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat jack("Jack", 13);
		std::cout << jack << std::endl;
		jack.deGrade();
		std::cout << jack << std::endl;
		jack.signForm(form1);
		jack.inGrade();
		std::cout << jack << std::endl;
		jack.inGrade();
		std::cout << jack << std::endl;
		jack.inGrade();
		std::cout << jack << std::endl;
		jack.signForm(form1);
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}