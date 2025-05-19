#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define PRINT_42 \
do { \
	std::cout << __PRETTY_FUNCTION__ << "\t called" << std::endl; \
} while (0)

class Brain
{
	public:
		// Constructors
			Brain();
			Brain(const Brain &original);
		// Destructors
			~Brain();
		// Operator overloads
			Brain &operator=(const Brain &original);
		// Getters
			std::string const	getIdea() const;
		// Setters
			void				setIdea(int i, std::string str);
		// Member functions

	private:
		std::string	_ideas[100];
};

#endif //BRAIN_HPP
