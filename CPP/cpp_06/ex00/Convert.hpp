#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Convert
{
	private:
		std::string		toconv;
		bool			flag_dot;
		char			symb;
		int				num;
		float			numf;
	public:
		Convert(std::string toconv);
		Convert();
		~Convert();

		void	init();
		int		isalnumber(std::string str);
		void	check_char(char symb);
		void	check_float(std::string toconv);
		void	check_double();
		void	convertaion_all(std::string toconv);
		class NumCheckExeptions : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
