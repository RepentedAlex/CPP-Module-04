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

class	Animal
{
	public:
		// Constructors
			Animal();
			Animal(Animal const &original);
		// Destructors
			virtual ~Animal();
		// Operator Overloads
			Animal &operator=(Animal const &original);
		// Getters
			std::string const	getType() const;
		// Setters
			void	setType(std::string type);
		// Member functions
			virtual void	makeSound() const;
	protected:
		std::string	_type;
	private:

};

#endif	//ANIMAL_HPP
