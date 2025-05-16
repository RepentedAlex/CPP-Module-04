#ifndef	CAT_HPP
#define	CAT_HPP

#include "Animal.hpp"

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
			void				setType(std::string type);
		// Member functions
			virtual void		makeSound() const;
	protected:

	private:

};

#endif	//CAT_HPP
