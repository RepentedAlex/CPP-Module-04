#include "Character.hpp"
#include "AMateria.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Character::Character() : _name("Missing_name")
{
	for (int i = 0 ; i < MAX_INVENTORY_SIZE ; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0 ; i < MAX_INVENTORY_SIZE ; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character &original)
{
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Character::~Character()
{
	for (int i = 0 ; i < MAX_INVENTORY_SIZE ; i++)
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
		}
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Character &Character::operator=(const Character &original)
{
	if (this != &original)
	{
		this->copyInventory(original);
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
bool	Character::checkInventoryFull() const
{
	for(int i = 0 ; i < MAX_INVENTORY_SIZE ; i++)
	{
		if (this->_inventory[i] == NULL)
			return (false);
	}
	return (true);
}

void	Character::copyInventory(const Character &original)
{
	if (this != &original)
		for (int i = 0 ; i < MAX_INVENTORY_SIZE ; i++)
			this->_inventory[i] = original._inventory[i];
}

//Need to have materias be `delete`-able
void				Character::equip(AMateria *m)
{
	if (this->checkInventoryFull() == false)
	{
		int	i = 0;
		while(i < MAX_INVENTORY_SIZE && this->_inventory[i])
			i++;
		this->_inventory[i] = m->clone();
		std::cout << "Materia added in slot " << i << std::endl;
	}
	else
		std::cout << "Can't add materia, inventory is full!" << std::endl;
}

void				Character::unequip(int idx)
{
	if (this->_inventory[idx])
		this->_inventory[idx] = NULL;
	else
		std::cout << "No item on slot " << idx << std::endl;
}

void				Character::use(int idx, ICharacter &target)
{
	if (!this->_inventory[idx])
		std::cout << this->getName() << " has no item equipped at slot " << idx << "." << std::endl;
	else
		this->_inventory[idx]->use(target);
}
