#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"

#define BLUE	"\033[1;95m"
#define CYAN	"\033[36m"
#define YELLOW	"\033[4;33m"
#define RESET	"\033[0m"

#define PRINT_SECTION(x) \
do { \
	std::cout << BLUE x RESET << std::endl; \
} while (0)


#define PRINT_SUBSECTION(x) \
do { \
	std::cout << YELLOW x RESET << std::endl; \
} while (0)

#define PRINT_TEST(x) \
do { \
	std::cout << CYAN x RESET << std::endl; \
} while (0)

#define PRINT(x) do { std::cout << x << std::endl; } while (0)

int	main()
{
	PRINT_SECTION("=== CONSTRUCTING ===");

	std::cout << std::endl;

	PRINT_SECTION("=== TESTING ===");

	std::cout << std::endl;

	/*{*/
	/*	PRINT_SUBSECTION("= Materias =");*/
	/*	Cure		c1;*/
	/*	Cure		*p_c1;*/
	/*	Ice			i1;*/
	/*	Ice			*p_i1;*/
	/*	AMateria	*p_am1;*/
	/**/
	/*	PRINT_TEST("Cloning: ");*/
	/*	PRINT("Cloning c1 into p_c1...");*/
	/*	p_c1 = c1.clone();*/
	/*	PRINT("Checking that p_c1 is of correct type: ");*/
	/*	std::cout << "c1 type: " << c1.getType() << " | p_c1 type: " << p_c1->getType() << std::endl << std::endl;*/
	/*	PRINT("Cloning i1 into p_i1...");*/
	/*	p_i1 = i1.clone();*/
	/*	PRINT("Checking that p_i1 is of correct type: ");*/
	/*	std::cout << "i1 type: " << i1.getType() << " | p_i1 type: " << p_i1->getType() << std::endl;*/
	/**/
	/*	std::cout << std::endl;*/
	/**/
	/*	PRINT_TEST("Clone on AMateria *ptr");*/
	/*	PRINT("Cloning c1 onto p_am1...");*/
	/*	p_am1 = c1.clone();*/
	/*	std::cout << "p-am1 type: " << p_am1->getType() <<*/
	/*	" (should be " << c1.getType() << ")" << std::endl << std::endl;*/
	/*	delete p_am1;*/
	/*	PRINT("Cloning i1 onto p_am1...");*/
	/*	p_am1 = i1.clone();*/
	/*	std::cout << "p-am1 type: " << p_am1->getType() <<*/
	/*	" (should be " << i1.getType() << ")" << std::endl;*/
	/**/
	/*	PRINT_TEST("Using materias");*/
	/*	Character	tmp("John Doe");*/
	/**/
	/*	PRINT("using c1:");*/
	/*	c1.use(tmp);*/
	/*	PRINT("using p_c1:");*/
	/*	p_c1->use(tmp);*/
	/*	PRINT("using i1:");*/
	/*	i1.use(tmp);*/
	/*	PRINT("using p_i1:");*/
	/*	p_i1->use(tmp);*/
	/**/
	/*	delete p_c1;*/
	/*	delete p_i1;*/
	/*	delete p_am1;*/
	/*}*/
	/**/
	/*std::cout << std::endl;*/

	{
		PRINT_SUBSECTION("= Full inventory =");
		Character	lockne("Lockne");
		Ice	i1;
		Ice	i2;
		Ice	i3;
		Ice	i4;
		Ice	i5;

		PRINT("Filling inventory...");
		lockne.equip(&i1);
		lockne.equip(&i2);
		lockne.equip(&i3);
		lockne.equip(&i4);
		lockne.equip(&i5);
		PRINT("Freeing place in slot 2");
		lockne.unequip(2);
		lockne.equip(&i5);
	}

	std::cout << std::endl;

	{
		PRINT_SUBSECTION("= Unequip =");
		Character	malingen("Malingend");
		AMateria	*mat = new Cure();

		malingen.equip(mat);
		malingen.use(0, malingen);

		malingen.unequip(0);
		PRINT("Trying to unequip empty slot");
		malingen.unequip(0);
		PRINT("Trying to unequip invalid slots");
		malingen.unequip(4);
		malingen.unequip(-1);

		delete mat;
	}

	std::cout << std::endl;

	/*{*/
	/*	PRINT_SUBSECTION("= Characters =");*/
	/*	Character	c1;*/
	/*	Character	*p_c1;*/
	/*	ICharacter	*p_ic1;*/
	/**/
	/*	PRINT_TEST("");*/
	/**/
	/*	std::cout << std::endl;*/
	/**/
	/*	PRINT_TEST("");*/
	/*}*/
	/**/
	/*std::cout << std::endl;*/

	{
		PRINT_SUBSECTION("= Subject main =");
		IMateriaSource	*src = new MateriaSource();
		Ice	*p_i1 = new Ice();
		Cure	*p_c1 = new Cure();
		src->learnMateria(p_i1);
		src->learnMateria(p_c1);

		ICharacter	*me = new Character("me");

		AMateria	*tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter	*bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete src;
		delete me;
		delete bob;
		delete p_i1;
		delete p_c1;
	}

	std::cout << std::endl;

	PRINT_SECTION("=== DESTRUCTING ===");
}
