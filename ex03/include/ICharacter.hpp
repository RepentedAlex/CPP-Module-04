#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

#include "AMateria.hpp"

//
// t_class
//		v_table table
//		void	*function_or_class(functions + variables)
//

class ICharacter
{
	public:
		// Constructors
			ICharacter();
		// Destructors;
			virtual ~ICharacter();
		// Operator overloads
		// Getters
			virtual std::string const	&getName() const = 0;
		// Setters
		// Member functions
			virtual void				equip(AMateria *m) = 0;
			virtual void				unequip(int idx) = 0;
			virtual void				use(int idx, ICharacter &targer) = 0;
};

#endif // ICHARACTER_HPP
