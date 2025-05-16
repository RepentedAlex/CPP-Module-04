#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	// Constructors
		WrongCat();
		WrongCat(const WrongCat &original);
	// Destructors
		~WrongCat();
	// Operator overloads
		WrongCat &operator=(const WrongCat &original);
	// Getters
		std::string const	getType() const;
	// Setters
		void				setType(std::string type);
	// Member functions
		void				makeSound() const;
};

#endif // WRONG_CAT_HPP
