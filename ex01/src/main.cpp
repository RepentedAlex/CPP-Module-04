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

/*int j= 0;*/
/*while (j < 10 && (delete array[j++], true));*/

int main()
{
	PRINT_SECTION("### TESTING ARRAY ###");
	{
		const Animal	*array[10];

		for (int i = 0 ; i < 10 ; i++)
		{
			if (i % 2)
				array[i] = new Cat();
			else
				array[i] = new Dog();
			if (!array[i])
			{
				for (int j = 0; j < i; delete array[j++]);
				throw std::runtime_error("Allocation failed");
			}
		}

		for (int j = 0 ; j < 10 ; j++)
		{
			std::cout << array[j]->getType() << std::endl;
			array[j]->makeSound();
			std::cout << std::endl;
		}

		for (int j = 0 ; j < 10 ; delete array[j++]);
	}
	PRINT_SECTION("### TESTING DEEP COPIES ###");
	{
		PRINT_SECTION("\tConstructing");
		Dog	*a = new Dog();
		if (!a)
			throw std::runtime_error("Allocation failed");

		a->setIdea(0, "Payer les impots.");
		a->setIdea(1, "Monter le dossier pour les APL.");
		a->setIdea(2, "Aller chercher la baballe.");
		a->setIdea(101, "Ouaf");

		Dog	*b = new Dog(*a);

		if (b == NULL) {
			delete a;
			throw std::runtime_error("Allocation failed");
		}
		std::cout << std::endl;

		PRINT_SECTION("Testing");
		std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
		a->printIdeas();
		std::cout << std::endl;

		PRINT_SECTION("Deconstructing");
		delete (a);
		std::cout << std::endl;

		PRINT_SECTION("Testing");
		std::cout << "The " << b->getType() << " b has the following: " << std::endl;
		b->printIdeas();
		std::cout << std::endl;

		PRINT_SECTION("Deconstructing");
		delete (b);
	}

	return (0);
}

