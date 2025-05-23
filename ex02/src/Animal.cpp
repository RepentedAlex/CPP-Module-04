#include "Animal.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
A_Animal::A_Animal()
{
	PRINT_42;
}

A_Animal::A_Animal(A_Animal const &original)
{
	PRINT_42;
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
A_Animal::~A_Animal()
{
	PRINT_42;
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
A_Animal &A_Animal::operator=(A_Animal const &original)
{
	PRINT_42;

	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const	A_Animal::getType() const
{
	return (this->_type);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	A_Animal::setType(std::string type)
{
	this->_type = type;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void A_Animal::makeSound() const
{
	std::cout << "Eldritch noises" << std::endl;
}
