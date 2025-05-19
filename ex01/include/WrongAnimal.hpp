#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

#define PRINT_42 \
do \
{ \
	std::cout << __PRETTY_FUNCTION__ << "\t called" << std::endl; \
} \
while (0)

class WrongAnimal
{
	public:
	// Constructors
		WrongAnimal();
		WrongAnimal(WrongAnimal const &original);
	// Destructors
		~WrongAnimal();
	// Operator overloads
		WrongAnimal &operator=(WrongAnimal const &original);
	// Getters
		std::string const	getType() const;
	// Setters
		void				setType(std::string type);
	// Member functions
		void				makeSound() const;

	protected:
		std::string	_type;
};

#endif //WRONG_ANIMAL_HPP
