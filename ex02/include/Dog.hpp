#ifndef	DOG_HPP
#define	DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public A_Animal
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
			void				setIdea(int i, std::string str);
			void				setType(std::string type);
		// Member functions
			virtual void		makeSound() const;
			void				printIdeas() const;
	protected:

	private:
		Brain	*_brain;
};

#endif	//DOG_HPP
