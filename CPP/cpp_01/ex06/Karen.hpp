#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Karen
{
	private:

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		typedef	void (*func[]);

	public:

		void complain(std::string level);
		Karen();
		~Karen();

};

#endif
