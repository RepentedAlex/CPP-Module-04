#include <vector>

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
	const Animal	*array[10];

	for (int i = 0 ; i < 10 ; i++)
	{
		if (i % 2)
		{
			array[i] = new Cat();
			if (!array[i])
			{
				std::cerr << "Cat allocation failed";
				exit(1);
			}
		}
		else
		{
			array[i] = new Dog();
			if (!array[i])
			{
				std::cerr << "Dog allocation failed";
				exit(1);
			}
		}
	}

	for (int j = 0 ; j < 10 ; j++)
	{
		std::cout << array[j]->getType() << std::endl;
		array[j]->makeSound();
		std::cout << std::endl;
	}

	for (int j = 0 ; j < 10 ; j++)
	{
		delete array[j];
	}

	PRINT_SECTION("### TESTING DEEP COPIES ###");
	{
		PRINT_SECTION("\tConstructing");
		Dog	*a = new Dog();
		if (!a)
		{
			std::cerr << "Allocation failed" << std::endl;
			exit(1);
		}

		a->setIdea(0, "Payer les impots.");
		a->setIdea(1, "Monter le dossier pour les APL.");
		a->setIdea(2, "Aller chercher la baballe.");
		a->setIdea(101, "Ouaf");

		Dog	*b = new Dog(*a);
	}

	return (0);
}

