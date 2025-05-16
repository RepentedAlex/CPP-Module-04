#include "Dog.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Dog::Dog() : Animal()
{
	PRINT_42;
	this->_type = "Dog";
}

Dog::Dog(Dog const &original) : Animal()
{
	PRINT_42;
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Dog::~Dog()
{
	PRINT_42;
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Dog &Dog::operator=(Dog const &original)
{
	PRINT_42;

	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const	Dog::getType() const
{
	return (this->_type);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	Dog::setType(std::string type)
{
	this->_type = type;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	Dog::makeSound() const
{
	std::cout << "Ouaf ouaf" << std::endl;
}
