#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
	protected:
	
	public:
		// Constructors
			AMateria();
			AMateria(std::string const &type);
			AMateria(const AMateria &original);
		// Destructors
			~AMateria();
		// Operator overloads
			AMateria &operator=(const AMateria &) = default;
		// Getters
			std::string const &getType() const;
		// Member functions
			virtual AMateria	*clone() const = 0;
			virtual void		use(ICharacter &target);

	private:
	
};

#endif // AMATERIA_HPP
