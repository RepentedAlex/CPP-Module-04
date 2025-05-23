#include "Brain.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Brain::Brain()
{
	PRINT_42;
}

Brain::Brain(Brain const &original)
{
	PRINT_42;
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Brain::~Brain()
{
	PRINT_42;
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Brain	&Brain::operator=(const Brain &original)
{
	PRINT_42;
	if (this == &original)
		return (*this);
	for (size_t i = 0 ; i < 100 ; i++)
	{
		if (!original._ideas->empty())
			this->_ideas[i].assign(original._ideas[i]);
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
std::string const	Brain::getIdea(size_t index) const
{
	if (index < 100)
		return (this->_ideas[index]);
	else
		return (NULL);
}

std::string const	*Brain::getIdeaREF(size_t index) const
{
	if (index < 100)
		return (&this->_ideas[index]);
	else
		return (NULL);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	Brain::setIdea(int i, std::string str)
{
	if (i < 100)
		this->_ideas[i] = str;
	else
	 std::cout << "There can only be 100 ideas in a brain." << std::endl;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////

