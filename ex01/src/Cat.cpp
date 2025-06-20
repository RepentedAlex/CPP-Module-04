#include <csignal>
#include <cstdlib>
#include <iostream>

#include "Cat.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Cat::Cat() : Animal()
{
	PRINT_42;
	this->_type = "Cat";
	this->_brain = new Brain;
	if (!this->_brain)
		throw std::runtime_error("Allocation failed");
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
	delete this->_brain;
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Cat &Cat::operator=(Cat const &original)
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
std::string const	Cat::getType() const
{
	return (this->_type);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	Cat::setIdea(int i, std::string str)
{
	this->_brain->setIdea(i, str);
}

void	Cat::setType(std::string type)
{
	this->_type = type;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	Cat::makeSound() const
{
	std::cout << "Miaou miaou les pétasses ?" << std::endl;
}

void	Cat::printIdeas() const
{
	for (size_t i = 0 ; i < 100 ; i++)
	{
		if (this->_brain->getIdea(i).empty())
			continue;
		std::cout << "idea [" << i << "]: " << this->_brain->getIdea(i) << std::endl;
	}
}

