#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP

#include <string>
#include <iostream>

#define PRINT_42 \
do \
{ \
	std::cout << __PRETTY_FUNCTION__ << "\t called" << std::endl; \
} \
while (0)

class	A_Animal
{
	public:
		// Constructors
			A_Animal();
			A_Animal(A_Animal const &original);
		// Destructors
			virtual ~A_Animal();
		// Operator Overloads
			virtual A_Animal &operator=(A_Animal const &original);
		// Getters
			virtual std::string const	getType() const;
		// Setters
			virtual void				setType(std::string type);
		// Member functions
			virtual void	makeSound() const = 0;
	protected:
		std::string	_type;
	private:

};

#endif	//ANIMAL_HPP
