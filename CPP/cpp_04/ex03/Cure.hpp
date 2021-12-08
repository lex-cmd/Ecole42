#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
	
	public:
		Cure();
		Cure(const Cure &other);
		~Cure();

		std::string const	&getType() const;
		virtual AMateria	*clone() const ;
		virtual void		use(ICharacter& target);
		Cure &operator=(const Cure &other);
};

std::ostream	&operator<<(const std::ostream &out, const Cure &other);

#endif
