#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#define PRINT_42 \
do { \
	std::cout << __PRETTY_FUNCTION__ << "\t called" << std::endl; \
} while (0)

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		// Constructors
			AMateria(std::string const &type);
		// Destructors
			virtual ~AMateria();
		// Operator overloads
		// Getters
			virtual std::string const &getType() const = 0;
		// Member functions
			virtual AMateria	*clone() const = 0;
			virtual void		use(ICharacter &target) = 0;
};

#endif // AMATERIA_HPP
