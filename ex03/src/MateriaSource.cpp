#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <cstddef>

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
MateriaSource::MateriaSource()
{
	for (int i = 0 ; i < MAX_LEARNT_MATERIAS ; i++)
		this->_learntMaterias[i] = NULL;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
MateriaSource::~MateriaSource()
{
	for (int i = 0 ; i < MAX_LEARNT_MATERIAS ; i++)
		if (this->_learntMaterias[i])
			delete this->_learntMaterias[i];
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////

///GETTERS//////////////////////////////////////////////////////////////////////

///SETTERS//////////////////////////////////////////////////////////////////////

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
bool	MateriaSource::checkSourceFull() const
{
	for (int i = 0 ; i < MAX_LEARNT_MATERIAS ; i++)
	{
		if (this->_learntMaterias[i] == NULL)
			return (false);
	}
	return (true);
}

void	MateriaSource::learnMateria(AMateria *ptr)
{
	if (this->checkSourceFull() == false)
	{
		int	i = 0;
		while (i < MAX_LEARNT_MATERIAS && this->_learntMaterias[i])
			i++;
		this->_learntMaterias[i] = ptr->clone();
	}
}

AMateria		*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0 ; i < MAX_LEARNT_MATERIAS ; i++)
	{
		if (this->_learntMaterias[i] && this->_learntMaterias[i]->getType().compare(type) == 0)
			return (this->_learntMaterias[i]->clone());
	}
	return (NULL);
}
