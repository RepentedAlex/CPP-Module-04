#include <csignal>
#include <cstdlib>
#include <iostream>

#include "Dog.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Dog::Dog() : A_Animal()
{
	PRINT_42;
	this->_type = "Dog";
	this->_brain = new Brain;
	if (!this->_brain)
		throw std::runtime_error("Allocation failed");
}

Dog::Dog(Dog const &original) : A_Animal()
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
	this->_brain = new Brain;
	if (!this->_brain)
		throw std::runtime_error("Allocation failed");
	*this->_brain = *original._brain;
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

void	Dog::printIdeas() const
{
	for (size_t i = 0 ; i < 100 ; i++)
	{
		if (this->_brain->getIdea(i).empty())
			continue;
		std::cout << "idea [" << i << "]: " << this->_brain->getIdea(i) << std::endl;
	}
}
