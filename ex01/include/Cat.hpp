#ifndef	CAT_HPP
#define	CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	public:
		// Constructors
			Cat();
			Cat(Cat const &original);
		// Destructors
			~Cat();
		// Operator overloads
			Cat &operator=(Cat const &original);
		// Getters
			std::string const	getType() const;
		// Setters
			void				setIdea(int i, std::string str);
			void				setType(std::string type);
		// Member functions
			virtual void		makeSound() const;
	protected:

	private:
		Brain	*_brain;
};

#endif	//CAT_HPP
