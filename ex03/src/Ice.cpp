#include "AMateria.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(Ice const &original) : AMateria("ice")
{
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Ice::~Ice()
{

}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Ice &Ice::operator=(const Ice &original)
{
	if (this != &original)
	{
		this->_type = original._type;
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
Ice	*Ice::clone() const
{
	Ice	*ret = new Ice(*this);

	return (ret);
}
void		Ice::use(ICharacter &target)
{
	(void)target;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
