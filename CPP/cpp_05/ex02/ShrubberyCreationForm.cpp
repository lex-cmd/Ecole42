#include "ShrubberyCreationForm.hpp"
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("RobotomyRequest", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string	filename(getTarget() + "_shrubbery");
	std::ofstream outf(filename);

	std::cout << executor.getName() << " выполнил форму " << this->getName() << std::endl;
	std::cout << "Create a file called " << filename << ", and write ASCII trees inside it, in the current directory." << std::endl;
	if (!outf)
	{
		std::cout << "File not be opened for writing!" << std::endl;
		std::exit(1);
	}

	outf << "                                   .         ;\n";
	outf << "      .              .              ;%     ;;\n";
	outf << "        ,           ,                :;%  %;\n";
	outf << "         :         ;                   :;%;'     .,\n";
	outf << ",.        %;     %;            ;        %;'    ,;\n";
	outf << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	outf << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
	outf << "    ;%;      %;        ;%;        % ;%;  ,%;'\n";
	outf << "     `%;.     ;%;     %;'         `;%%;.%;'\n";
	outf << "      `:;%.    ;%%. %@;        %; ;@%;%'\n";
	outf << "         `:%;.  :;bd%;          %;@%;'\n";
	outf << "           `@%:.  :;%.         ;@@%;'\n";
	outf << "             `@%.  `;@%.      ;@@%;\n";
	outf << "               `@%%. `@%%    ;@@%;\n";
	outf << "                 ;@%. :@%%  %@@%;\n";
	outf << "                   %@bd%%%bd%%:;\n";
	outf << "                     #@%%%%%:;;\n";
	outf << "                     %@@%%%::;\n";
	outf << "                     %@@@%(o);  . '\n";
	outf << "                     %@@@o%;:(.,'\n";
	outf << "                 `.. %@@@o%::;\n";
	outf << "                    `)@@@o%::;\n";
	outf << "                     %@@(o)::;\n";
	outf << "                    .%@@@@%::;\n";
	outf << "                    ;%@@@@%::;.\n";
	outf << "                   ;%@@@@%%:;;;.\n";
	outf << "               ...;%@@@@@%%:;;;;,..\n";
	outf << "------------------------------------------------\n";
	outf.close();
}

std::string		ShrubberyCreationForm::getTarget() const
{
	return (target);
}

std::ostream	 &operator<<(std::ostream &out, const ShrubberyCreationForm &other)
{
	out << "Form name " << other.getName() << " grade " << other.getGrade() << ", status " << other.getSign() << ", target " << other.getTarget();
	return (out);
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	const_cast<std::string&>(target) = const_cast<std::string&>(other.target);

	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
}
