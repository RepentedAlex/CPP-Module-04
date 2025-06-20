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
	A_Animal	*dog = new Dog();
	A_Animal	*cat = new Cat();
//	A_Animal	*ani = new A_Animal();  // Abstract class should fail to compile if uncomnmented

	dog->makeSound();
	cat->makeSound();
//	ani->makeSound();

	delete dog;
	delete cat;
//	delete ani;
	return (0);
}

