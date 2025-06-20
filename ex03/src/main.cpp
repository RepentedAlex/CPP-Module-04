#include "AMateria.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "Ice.hpp"

#define BLUE	"\033[34m"
#define RESET	"\033[0m"

#define PRINT_SECTION(x) \
do { \
	std::cout << BLUE x RESET << std::endl; \
} while (0)

int	main()
{
	PRINT_SECTION("=== CONSTRUCTING ===");
	Cure		c1;
	Cure		*c2;
	Ice			i1;
	Ice			*i2;
	Character	char1("Malingen");
	Character	char2;

	PRINT_SECTION("=== TESTING ===");
	std::cout << "c1 is of type: " << c1.getType() << std::endl;
	c1.use(char1);
	c2 = c1.clone();
	std::cout << "c2 is of type: " << c2->getType() << std::endl;
	c2->use(char1);


	std::cout << "i1 is of type: " << i1.getType() << std::endl;
	i1.use(char1);
	i2 = i1.clone();
	std::cout << "i2 is of type: " << i2->getType() << std::endl;
	i2->use(char1);

	char1.equip(c2);
	char1.use(0, char2);
	char1.use(1, char2);
	char1.use(0, char1);

	PRINT_SECTION("=== DESTRUCTING ===");
	delete c2;
	delete i2;
}
