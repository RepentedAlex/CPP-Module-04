#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define PRINT_42 \
do { \
	std::cout << __PRETTY_FUNCTION__ << "\t called" << std::endl; \
} while (0)

class Character : public ICharacter
{
	public:
		// Constructors
			Character();
			Character(const Character &original);
		// Destructors
			~Character();
		// Operator overloads
			Character &operator=(const Character &original);
		// Getters
			std::string const	&getName() const;
		// Setters
		// Member functions
			void				equip(AMateria *m);
			void				unequip(int idx);
			void				use(int idx, ICharacter &target);

	private:
		std::string	_name;
		AMateria	*_inventory[4];
};

#endif // CHARACTER_HPP
