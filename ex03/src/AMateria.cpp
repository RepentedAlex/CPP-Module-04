#include "AMateria.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
AMateria::AMateria() : _type("none")
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &original)
{
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
AMateria::~AMateria()
{

}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
AMateria	&AMateria::operator=(const AMateria &original)
{
	if (this != &original)
	{
		this->_type = original.getType();
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const &AMateria::getType() const
{
	return (this->_type);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	AMateria::setType(const std::string type)
{
	if (this->getType().compare(type) != 0)
		this->_type = type;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	AMateria::use(ICharacter &target)
{
	(void)target;
}


