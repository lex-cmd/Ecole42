#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:
	
	public:
		Ice();
		Ice(const Ice &other);
		~Ice();

		std::string const	&getType() const;
		virtual AMateria	*clone() const ;
		virtual void		use(ICharacter& target);
		Ice &operator=(const Ice &other);
};

std::ostream	&operator<<(const std::ostream &out, const Ice &other);

#endif
