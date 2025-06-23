#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <cstddef>

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
MateriaSource::MateriaSource()
{
	for (int i = 0 ; i < MAX_LEARNT_MATERIAS ; i++)
		this->_learntMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &original)
{
	for (int i = 0 ; i < MAX_LEARNT_MATERIAS ; i++)
		this->_learntMaterias[i] = NULL;
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
MateriaSource::~MateriaSource()
{
	for (int i = 0 ; i < MAX_LEARNT_MATERIAS ; i++)
		if (this->_learntMaterias[i] != NULL)
			delete this->_learntMaterias[i];
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
MateriaSource	&MateriaSource::operator=(const MateriaSource &original)
{
	if (this != &original)
	{
		this->copyLearntMaterias(original);
	}
	return (*this);
}

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

void	MateriaSource::copyLearntMaterias(const MateriaSource &original)
{
	for (int i = 0; i < MAX_LEARNT_MATERIAS; ++i)
	{
		if (this->_learntMaterias[i])
		{
			delete this->_learntMaterias[i];
			this->_learntMaterias[i] = NULL;
		}
		if (original._learntMaterias[i])
			this->_learntMaterias[i] = original._learntMaterias[i]->clone();
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

void	MateriaSource::dumpMateriasLearnt() const
{
	for (int i = 0 ; i < MAX_LEARNT_MATERIAS ; i++)
	{
		if (this->_learntMaterias[i])
			std::cout << "Slot [" << i << "]: " << this->_learntMaterias[i]->getType() <<
			" (" << this->_learntMaterias[i] << ')' << std::endl;
		else
			std::cout << "Slot [" << i << "]: Empty (" << this->_learntMaterias[i] << ')' << std::endl;
	}
}

void	MateriaSource::learnMateria(AMateria *ptr)
{
	if (this->checkSourceFull() == false)
	{
		int	i = 0;
		while (i < MAX_LEARNT_MATERIAS && this->_learntMaterias[i])
			i++;
		this->_learntMaterias[i] = ptr;
	}
}

