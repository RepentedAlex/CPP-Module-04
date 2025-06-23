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

	{
		PRINT_SUBSECTION("= Materias =");
		Cure		c1;
		Cure		*p_c1;
		Ice			i1;
		Ice			*p_i1;
		AMateria	*p_am1;

		PRINT_TEST("Cloning: ");
		PRINT("Cloning c1 into p_c1...");
		p_c1 = c1.clone();
		PRINT("Checking that p_c1 is of correct type: ");
		std::cout << "c1 type: " << c1.getType() << " | p_c1 type: " << p_c1->getType() << std::endl << std::endl;
		PRINT("Cloning i1 into p_i1...");
		p_i1 = i1.clone();
		PRINT("Checking that p_i1 is of correct type: ");
		std::cout << "i1 type: " << i1.getType() << " | p_i1 type: " << p_i1->getType() << std::endl;

		std::cout << std::endl;

		PRINT_TEST("Clone on AMateria *ptr");
		PRINT("Cloning c1 onto p_am1...");
		p_am1 = c1.clone();
		std::cout << "p-am1 type: " << p_am1->getType() <<
		" (should be " << c1.getType() << ")" << std::endl << std::endl;
		delete p_am1;
		PRINT("Cloning i1 onto p_am1...");
		p_am1 = i1.clone();
		std::cout << "p-am1 type: " << p_am1->getType() <<
		" (should be " << i1.getType() << ")" << std::endl;

		std::cout << std::endl;

		PRINT_TEST("Using materias");
		Character	tmp("John Doe");

		PRINT("using c1:");
		c1.use(tmp);
		PRINT("using p_c1:");
		p_c1->use(tmp);
		PRINT("using i1:");
		i1.use(tmp);
		PRINT("using p_i1:");
		p_i1->use(tmp);

		delete p_c1;
		delete p_i1;
		delete p_am1;
	}

	std::cout << std::endl;

	{
		PRINT_SUBSECTION("= Inventory =");
		Character	*lockne= new Character("Lockne");
		Ice	*i1 = new Ice();
		Ice	*i2 = new Ice();
		Ice	*i3 = new Ice();
		Ice	*i4 = new Ice();
		Ice	*i5 = new Ice();

		PRINT_TEST("Empty inventory:");

		lockne->equip(i1);
		lockne->equip(i2);
		lockne->equip(i3);
		lockne->equip(i4);
		lockne->dumpInventory();

		PRINT_TEST("Full inventory (inventory is full from previous test:");
		lockne->equip(i5);
		lockne->dumpInventory();

		PRINT_TEST("Empty slot in middle of inventory:");
		lockne->unequip(2);
		lockne->equip(i5);
		lockne->dumpInventory();

		delete lockne;
	}

	std::cout << std::endl;

	{
		PRINT_SUBSECTION("= Unequip =");
		Character	*malingen = new Character("Malingend");
		AMateria	*mat = new Cure();

		malingen->equip(mat);
		malingen->use(0, *malingen);


		malingen->unequip(0);
		PRINT("Trying to unequip empty slot");
		malingen->unequip(0);
		PRINT("Trying to unequip invalid slots");
		malingen->unequip(4);
		malingen->unequip(-1);

		delete malingen;
	}

	std::cout << std::endl;

	{
		PRINT_SUBSECTION("= Floor =");
		Character	*malingen = new Character("Malingen");
		Character	*lockne = new Character("Lockne");
		Ice	*i1 = new Ice();
		Cure	*c1 = new Cure();

		std::cout << "floor[0] type: " << " (" << Character::_floor[0] << ')' << std::endl;
		std::cout << "floor[1] type: " << " (" << Character::_floor[0] << ')' << std::endl;

		lockne->equip(i1);
		lockne->equip(c1);
		lockne->unequip(0);
		lockne->unequip(1);

		PRINT_TEST("Floor should hold an Ice and a Cure materia:");
		std::cout << "floor[0] type: " << Character::_floor[0]->getType() <<
		" (" << Character::_floor[0] << ')' << std::endl;
		std::cout << "floor[1] type: " << Character::_floor[1]->getType() <<
		" (" << Character::_floor[1] << ')' << std::endl;

		PRINT_TEST("Deconstructing only one character, floor should not show empty:");
		delete malingen;
		std::cout << "floor[0] type: " << Character::_floor[0]->getType() <<
		" (" << Character::_floor[0] << ')' << std::endl;
		std::cout << "floor[1] type: " << Character::_floor[1]->getType() <<
		" (" << Character::_floor[1] << ')' << std::endl;
		PRINT_TEST("Deconstructing remaining character, floor should show empty:");
		delete lockne;
		std::cout << "floor[0] type: " << " (" << Character::_floor[0] << ')' << std::endl;
		std::cout << "floor[1] type: " << " (" << Character::_floor[1] << ')' << std::endl;
	}

	std::cout << std::endl;

	{
		PRINT_SUBSECTION("= Deep copies =");

		Character	*original = new Character("Original");

		original->equip(new Ice());
		original->equip(new Cure());

		std::cout << std::endl;

		original->dumpInventory();

		std::cout << std::endl;

		PRINT("Creating copy");
		Character	*copy = new Character(*original);
		copy->dumpInventory();

		std::cout << std::endl;

		PRINT("Both should be able to use Materia");
		original->use(0, *original);
		copy->use(0, *copy);

		std::cout << std::endl;

		PRINT("Unequiping materia from original");
		original->unequip(0);
		original->use(0, *original);

		std::cout << std::endl;

		PRINT_TEST("Copy should still be able to use Materia");
		copy->use(0, *copy);

		delete original;
		delete copy;
	}

	std::cout << std::endl;

	{
		PRINT_SUBSECTION("= Unknown Materia =");
		IMateriaSource	*src = new MateriaSource();

		src->learnMateria(new Ice());

		AMateria *unknown = src->createMateria("fire");
		if (!unknown)
			std::cout << "Couldn't create unknown materia \"fire\"" << std::endl;

		delete src;
	}

	std::cout << std::endl;

	{
		PRINT_SUBSECTION("= Copy of MateriaSource =");
		MateriaSource *src = new MateriaSource();

		PRINT("Filling original MateriaSource");
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		std::cout << std::endl;

		PRINT("Original dump");
		src->dumpMateriasLearnt();

		std::cout << std::endl;

		PRINT("Copying original MateriaSource");
		MateriaSource	*copy = new MateriaSource(*src);

		std::cout << std::endl;

		PRINT("Copy dump");
		copy->dumpMateriasLearnt();

		delete src;
		delete copy;
	}

	std::cout << std::endl;

	{
		PRINT_SUBSECTION("= Subject main =");
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter	*me = new Character("me");

		AMateria	*tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter	*bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl;

	PRINT_SECTION("=== DESTRUCTING ===");

	return (0);
}
