# include "header.h"

int main(void)
{
    {
    std::cout << std::endl << "-----MATERIA SOURCE -----------" << std::endl;

    IMateriaSource *src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    AMateria *tmp = src->createMateria("ice");
    AMateria *tmp2 = src->createMateria("cure");
    
    std::cout << std::endl << "-----------CHARACTER------------" << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* enemy = new Character("enemy");
    std::cout << "Name: " <<  me->getName() << std::endl;
    std::cout << "Name: " <<  enemy->getName() << std::endl;
    std::cout << std::endl << "--------------EQUIP----------------" << std::endl;
    me->equip(tmp);
    me->equip(tmp2);
    
    std::cout << std::endl << "--------------USING----------------" << std::endl;
    me->use(0, *enemy);
    me->use(1, *enemy);
    me->use(2, *enemy); // Inventory 1 not equipped

    std::cout << std::endl << "----------COPY-----CHARACTER------" << std::endl;
    std::cout << "1. Copy constructor" << std::endl;
    ICharacter *me_copy = new Character(*dynamic_cast<Character*>(me));
    std::cout << me_copy->getName() << std::endl;
    me_copy->use(0, *enemy);
    std::cout << "2. Assignment operator" << std::endl;
    ICharacter *new_me = new Character();
    *dynamic_cast<Character*>(new_me) = *dynamic_cast<Character*>(me);
    new_me->use(0, *enemy);

    std::cout << std::endl << "--------------UNEQUIP----------------" << std::endl;
    me->unequip(0);
    me->unequip(1);
    me->unequip(2); // Inventory 2 not equipped

    std::cout << std::endl << "----------COPY-----MATERIA------" << std::endl;
    AMateria *df = new Ice();
    AMateria *df2 = new Ice();
    *dynamic_cast<Ice*>(df) = *dynamic_cast<Ice*>(df2);

    std::cout << std::endl << "----------DESTRUCTION------" << std::endl;
    delete me;
    delete enemy;
    delete me_copy;
    delete new_me;
    delete src;
    delete df;
    delete df2;
    }
    std::cout << std::endl << "------ SUBJECTS TESTS -----------" << std::endl;

    {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
    }

}