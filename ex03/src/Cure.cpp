#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(Cure const &original) : AMateria("cure")
{
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Cure::~Cure()
{

}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Cure &Cure::operator=(const Cure &original)
{
	if (this != &original)
	{
		this->_type = original._type;
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
Cure	*Cure::clone() const
{
	Cure	*ret = new Cure(*this);
	return (ret);
}
void		Cure::use(ICharacter &target)
{
	(void)target;
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
