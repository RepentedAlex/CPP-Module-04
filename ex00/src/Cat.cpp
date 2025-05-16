#include "Cat.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Cat::Cat() : Animal()
{
	PRINT_42;
	this->_type = "Cat";
}

Cat::Cat(Cat const &original) : Animal()
{
	PRINT_42;
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Cat::~Cat()
{
	PRINT_42;
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Cat &Cat::operator=(Cat const &original)
{
	PRINT_42;

	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const	Cat::getType() const
{
	return (this->_type);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	Cat::setType(std::string type)
{
	this->_type = type;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	Cat::makeSound() const
{
	std::cout << "Miaou miaou les pétasses ?" << std::endl;
}
