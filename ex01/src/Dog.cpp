#include "Dog.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Dog::Dog() : Animal()
{
	PRINT_42;
	this->_type = "Dog";
	this->_brain = new Brain;
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
	delete this->_brain;
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Dog &Dog::operator=(Dog const &original)
{
	PRINT_42;

	if (this == &original)
		return (*this);
	this->_type = original._type;
	this->_brain = original._brain;
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const	Dog::getType() const
{
	return (this->_type);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	Dog::setIdea(int i, std::string str)
{
	this->_brain->setIdea(i, str);
}

void	Dog::setType(std::string type)
{
	this->_type = type;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	Dog::makeSound() const
{
	std::cout << "Ouaf ouaf" << std::endl;
}
