# include "header.h"

int main(void)
{
    IMateriaSource *src = new MateriaSource();

    src->learnMateria(new Ice());
    AMateria *tmp = src->createMateria("ice");
    
    ICharacter* me = new Character("me");
    ICharacter* enemy = new Character("enemy");
    std::cout << me->getName() << std::endl;
    std::cout << std::endl << "--------------EQUIP----------------" << std::endl;
    me->equip(tmp);
    
    std::cout << std::endl << "--------------USING----------------" << std::endl;
    me->use(0, *enemy);
    me->use(1, *enemy); // Inventory 1 not equipped

    ICharacter *me_copy = new Character(*dynamic_cast<Character*>(me));
    me->unequip(0);

    std::cout << std::endl << "--------------COPY----------------" << std::endl;
    std::cout << me_copy->getName() << std::endl;
    me_copy->use(0, *enemy);
}