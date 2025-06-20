#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class	IMateriaSource
{
	public:
		// Constructors
		// Deconstructors
			virtual ~IMateriaSource();
		// Operator overloads
		// Getters
		// Setters
		// Member functions
			virtual AMateria*	createMateria(std::string const & type) = 0;
			virtual void		learnMateria(AMateria*) = 0;
};

#endif // !IMATERIASOURCE_HPP
