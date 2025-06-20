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
	PRINT_SECTION("### TEST CORRECT ###");
	PRINT_SECTION("\tInstanciation des objets");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	PRINT_SECTION("\tAffichage des types");
	std::cout << meta->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	PRINT_SECTION("\tLes sons");
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	PRINT_SECTION("\tDelete des allocations");
	delete j;
	delete i;
	delete meta;

	std::cout << std::endl << std::endl;

	PRINT_SECTION("### TEST WRONGANIMAL/WRONGCAT");
	PRINT_SECTION("\tInstanciation des objets");
	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_i = new WrongCat();
	PRINT_SECTION("\tAffichage des types");
	std::cout << "wrong_cat " << w_i->getType()<< std::endl;
	std::cout << "wrong_animal " << w_meta->getType() << std::endl;
	PRINT_SECTION("\tLes sons");
	w_i->makeSound(); //will output the cat sound!
	w_meta->makeSound();

	PRINT_SECTION("\tDelete des allocations");
	delete w_i;
	delete w_meta;

	return (0);
}

// int	main()
// {
// 	Cat	minou;
// 	Dog	oslo;
// 	Dog	olive;
//
// 	std::cout << "I am a : " << olive.getType() << std::endl;
// 	olive.makeSound();
// 	std::cout << "I am a : " << minou.getType() << std::endl;
// 	minou.makeSound();
// 	std::cout << "I am a : " << oslo.getType() << std::endl;
// 	oslo.makeSound();
// }
