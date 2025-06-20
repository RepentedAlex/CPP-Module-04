#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// Constructors
			Ice();
			Ice(Ice const &original);
		// Destructors
			~Ice();
		// Operator overloads
			Ice	&operator=(Ice const &original);
		// Getters
		// Setters
		// Member functions
			Ice					*clone() const;
			void				use(ICharacter &target);
};

#endif // !ICE_HPP
