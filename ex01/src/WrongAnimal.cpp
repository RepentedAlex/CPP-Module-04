#include "WrongAnimal.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
WrongAnimal::WrongAnimal()
{
	PRINT_42;
}

WrongAnimal::WrongAnimal(WrongAnimal const &original)
{
	PRINT_42;
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
WrongAnimal::~WrongAnimal()
{
	PRINT_42;
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &original)
{
	PRINT_42;

	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const	WrongAnimal::getType() const
{
	return (this->_type);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void WrongAnimal::makeSound() const
{
	std::cout << "WRONG Eldritch noises" << std::endl;
}
