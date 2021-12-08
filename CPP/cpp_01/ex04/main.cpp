#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char **argv)
{
	std::string	strInput;
	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	std::ifstream infile(argv[1]);
	std::ofstream outfile("pepe.replace");
	std::string::size_type i = 0;

	if (argc == 4)
	{
		if (!infile)
		{
			std::cerr << argv[1] << ": Could not be opened for reading!" << std::endl;
			return (1);
		}
		if (!outfile)
		{
			std::cerr << argv[1] << ": Could not be opened for writing!" << std::endl;
			return (1);
		}
		while (std::getline(infile, strInput))
		{
			while ((i = strInput.find(s1)) != std::string::npos)
			{
				strInput.replace(i, s1.length(), s2);
				i += s2.length();
			}
			outfile << strInput << "\n";
		}
		infile.close();
		outfile.close();
		return (0);
	}
	std::cout << "./replace file string1 string2" << std::endl;
	return (1);
}
