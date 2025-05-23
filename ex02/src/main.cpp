#include <cstdio>
#include <exception>
#include <vector>
#include <cstdlib>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define BLUE	"\033[34m"
#define RESET	"\033[0m"

#define PRINT_SECTION(x) \
do { \
	std::cout << BLUE x RESET << std::endl; \
} while (0)

int main()
{
	Dog	a;
	Cat	b;

	return (0);
}

