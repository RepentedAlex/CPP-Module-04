#include "WrongCat.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
WrongCat::WrongCat() : WrongAnimal()
{
	PRINT_42;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &original) : WrongAnimal()
{
	PRINT_42;
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
WrongCat::~WrongCat()
{
	PRINT_42;
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
WrongCat &WrongCat::operator=(WrongCat const &original)
{
	PRINT_42;

	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const	WrongCat::getType() const
{
	return (this->_type);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	WrongCat::setType(std::string type)
{
	this->_type = type;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	WrongCat::makeSound() const
{
	std::cout << "Meow meow nibba" << std::endl;
}
