#include "Character.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Character::Character() : _name("Missing_name")
{
	PRINT_42;
}

Character::Character(const Character &original)
{
	PRINT_42;
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Character::~Character()
{
	PRINT_42;
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Character &Character::operator=(const Character &original)
{
	PRINT_42;
	if (this != &original)
	{
		this->_inventory = original.;
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const	&Character::getName() const
{
	return (this->_name);
}

///SETTERS//////////////////////////////////////////////////////////////////////

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void				Character::equip(AMateria *m)
{
	unsigned int	i = 0;
	while (!this->_inventory[i] || i < 4)
		i++;
	this->_inventory[i] = m;
}

void				unequip(int idx)
{
}

void				use(int idx, ICharacter &target)
{
}
