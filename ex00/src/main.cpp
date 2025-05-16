#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Test correct" << std::endl;
	std::cout << "Instanciation des objets" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "Fin Instanciation des objets" << std::endl;
	std::cout << "Affichage des types" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "Fin Affichage des types" << std::endl;
	std::cout << "Les sons" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "Fin Des sons" << std::endl;

	std::cout << "Delete des allocations" << std::endl;
	delete j;
	delete i;
	delete meta;
	std::cout << "Fin Delete des allocations" << std::endl;

	std::cout << std::endl;

	std::cout << "Test WrongAnimal et WrongCat" << std::endl;
	std::cout << "Instanciation des objets" << std::endl;
	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_i = new WrongCat();
	std::cout << "Fin Instanciation des objets" << std::endl;
	std::cout << "Affichage des types" << std::endl;
	std::cout << w_i->getType() << " " << std::endl;
	std::cout << "Fin Affichage des types" << std::endl;
	std::cout << "Les sons" << std::endl;
	w_i->makeSound(); //will output the cat sound!
	w_meta->makeSound();
	std::cout << "Fin Des sons" << std::endl;

	std::cout << "Delete des allocations" << std::endl;
	delete w_i;
	delete w_meta;
	std::cout << "Fin Delete des allocations" << std::endl;
	return 0;
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
