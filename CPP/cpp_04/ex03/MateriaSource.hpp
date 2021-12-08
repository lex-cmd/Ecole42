#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# define NUMOFMAT 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*materias[NUMOFMAT];
		int			index_mat;
	public:
		~MateriaSource();
		MateriaSource();
		MateriaSource(const MateriaSource &other);

		void learnMateria(AMateria *other);
		AMateria* createMateria(std::string const &type);

		MateriaSource &operator=(const MateriaSource &other);
};

#endif
