#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Constructors
			Cure();
			Cure(Cure const &original);
		// Destructors
			~Cure();
		// Operator overloads
			Cure	&operator=(Cure const &original);
		// Getters
		// Setters
		// Member functions
			Cure				*clone() const;
			void				use(ICharacter &target);
};

#endif // CURE_HPP
