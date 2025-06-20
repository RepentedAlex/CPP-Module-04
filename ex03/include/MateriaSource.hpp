#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define MAX_LEARNT_MATERIAS 4

class MateriaSource : public IMateriaSource
{
	public:
	// Constructors
		MateriaSource();
		MateriaSource(const MateriaSource &original);
	// Destructors
		~MateriaSource();
	// Operator overloads
		MateriaSource &operator=(const MateriaSource &original);
	// Getters
	// Setters
	// Member functions
		bool		checkSourceFull() const;
		void		copyLearntMaterias(const MateriaSource &original);
		void		learnMateria(AMateria *ptr);
		AMateria	*createMateria(std::string const &type);

	private:
		AMateria	*_learntMaterias[MAX_LEARNT_MATERIAS];
};

#endif // !MATERIASOURCE_HPP
