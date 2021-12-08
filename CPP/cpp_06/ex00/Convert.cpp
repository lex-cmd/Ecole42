#include "Convert.hpp"

Convert::Convert(std::string toconv)
{
	init();
	convertaion_all(toconv);
}

Convert::Convert()
{
}

Convert::~Convert()
{

}

void	Convert::init()
{
	flag_dot= false;
}

const char* Convert::NumCheckExeptions::what() const throw()
{
	return "NumCheckExeptions: out of range";
}

void	Convert::convertaion_all(std::string toconv)
{
		if (isalnumber(toconv) == 1)
		{
			num = std::stoi(toconv);
			if (num > 2147483647 || num < -2147483648)
				throw Convert::NumCheckExeptions();
			if (num > 0 && num <= 127)
				symb = char(num);
			check_char(symb);
			std::cout << "int: " << static_cast<int>(num) << std::endl;
			check_float(toconv);
			check_double();
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << toconv << "f\n" << "double: " << toconv << std::endl;
		}
}

int		Convert::isalnumber(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if ((str[i] < '0' && str[i] != '.' && str[i] != '-') || (str[i] > '9'  && str[i] != 'f'))// || (str[i] > '9' && str[i] != 'f') || str[str.length() - 1] != 'f')
			return (-1);
		if (!flag_dot && str[i] == '.' && str[i + 1] != '0')
			flag_dot = true;
		if (str[i] == '.' && str[i + 1] == '.')
			return (-1);
		if (str[i] == '-' && str[i + 1] == '-')
			return (-1);
		i++;
	}
	return (1);
}

void	Convert::check_char(char symb)
{
	std::cout << "char: ";
	if (symb < 33 || symb > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << static_cast<char>(symb) << "\'" << std::endl;
}

void	Convert::check_float(std::string toconv)
{
	// int	flag = toconv.length();
	std::cout << "float: ";
	numf = (std::stof(toconv));
	if (flag_dot)
		std::cout << static_cast<float>(numf) << "f";
	else
	{
		std::cout.precision(1);
		std::cout << std::fixed << static_cast<float>(num) << "f";
	}
	std::cout << std::endl;
}

void	Convert::check_double()
{
	std::cout << "double: ";
	if (flag_dot)
		std::cout << static_cast<double>(numf);
	else
	{
		std::cout.precision(1);
		std::cout << std::fixed << static_cast<double>(numf);
	}
	std::cout << std::endl;
}
