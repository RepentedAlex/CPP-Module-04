#include "Animal.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Animal::Animal()
{
	PRINT_42;
}

Animal::Animal(Animal const &original)
{
	PRINT_42;
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Animal::~Animal()
{
	PRINT_42;
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Animal &Animal::operator=(Animal const &original)
{
	PRINT_42;

	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const	Animal::getType() const
{
	return (this->_type);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	Animal::setType(std::string type)
{
	this->_type = type;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void Animal::makeSound() const
{
	std::cout << "Eldritch noises" << std::endl;
}
