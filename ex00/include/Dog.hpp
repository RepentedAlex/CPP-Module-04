#ifndef	DOG_HPP
#define	DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		// Constructors
			Dog();
			Dog(Dog const &original);
		// Destructors
			~Dog();
		// Operator overloads
			Dog &operator=(Dog const &original);
		// Getters
			std::string	const	getType() const;
		// Setters
			void				setType(std::string type);
		// Member functions
			virtual void		makeSound() const;
	protected:

	private:

};

#endif	//DOG_HPP
