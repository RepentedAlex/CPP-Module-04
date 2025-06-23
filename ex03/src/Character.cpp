#include "Character.hpp"
#include "AMateria.hpp"

int	Character::_nbCharacters = 0;
AMateria	*Character::_floor[FLOOR_SIZE] = {NULL};

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Character::Character() : _name("Missing_name")
{
	_nbCharacters++;
	for (int i = 0 ; i < MAX_INVENTORY_SIZE ; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	_nbCharacters++;
	for (int i = 0 ; i < MAX_INVENTORY_SIZE ; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character &original)
{
	_nbCharacters++;
	for (int i = 0 ; i < MAX_INVENTORY_SIZE ; i++) this->_inventory[i] = NULL;
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Character::~Character()
{
	_nbCharacters--;
	for (int i = 0 ; i < MAX_INVENTORY_SIZE ; i++)
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}

	if (_nbCharacters == 0)
	{
		for (int i = 0 ; i < FLOOR_SIZE ; i++)
			if (this->_floor[i] != NULL)
			{
				delete this->_floor[i];
				this->_floor[i] = NULL;
			}
	}
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Character &Character::operator=(const Character &original)
{
	if (this != &original)
	{
		for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		this->copyInventory(original);
		this->_name = original.getName();
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const	&Character::getName() const
{
	return (this->_name);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	Character::setName(std::string const &name)
{
	this->_name = name;
}

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
		{
			if (this->_inventory[i])
				this->unequip(i);
			if (original._inventory[i])
				this->_inventory[i] = original._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
}

void	Character::dumpInventory() const
{
	for (int i = 0 ; i < MAX_INVENTORY_SIZE ; i++)
	{
		if (this->_inventory[i])
			std::cout << this->getName() << " inventory slot [" << i << "]: " <<
			this->_inventory[i]->getType() << " (" << this->_inventory[i] << ')' << std::endl;
		else
			std::cout << "Slot [" << i << "]: Empty (" << this->_inventory[i] << ')' << std::endl;
	}
}

//Need to have materias be `delete`-able
void				Character::equip(AMateria *m)
{
	if (!m)
		return ;
	if (this->checkInventoryFull() == false)
	{
		int	i = 0;
		while(i < MAX_INVENTORY_SIZE && this->_inventory[i])
			i++;
		this->_inventory[i] = m->clone();
		(delete m, m = NULL);
		std::cout << "Materia added in slot " << i << std::endl;
	}
	else
		std::cout << "Can't add materia, inventory is full!" << std::endl;
}

void				Character::unequip(int idx)
{
	if ((idx >= 0 && idx < MAX_INVENTORY_SIZE) && this->_inventory[idx])
	{
		for (int i = 0 ; i <= FLOOR_SIZE ; i++)
		{
			if (i == FLOOR_SIZE)
			{
				std::cout << "Can't unequip, floor is full!" << std::endl;
				return ;
			}
			if (this->_floor[i] == NULL)
			{
				this->_floor[i] = this->_inventory[idx];
				break ;
			}
		}
		this->_inventory[idx] = NULL;
	}
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
