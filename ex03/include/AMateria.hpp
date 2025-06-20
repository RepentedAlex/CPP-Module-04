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
			AMateria();
			AMateria(std::string const &type);
			AMateria(const AMateria &original);
		// Destructors
			virtual ~AMateria();
		// Operator overloads
			AMateria	&operator=(const AMateria &original);
		// Getters
			virtual std::string const	&getType() const;
		// Setters
			void	setType(const std::string type);
		// Member functions
			virtual AMateria	*clone() const = 0;
			virtual void		use(ICharacter &target) = 0;
};

#endif // AMATERIA_HPP
