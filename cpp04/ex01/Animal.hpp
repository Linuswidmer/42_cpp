#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>
# include "Brain.hpp"
using namespace std;

class Animal {
protected:
    string _type;

public:
    Animal(void);
    virtual ~Animal(void);
    Animal(const Animal &copy);
    Animal& operator=(const Animal &other);

    string          getType(void);
    virtual void    makeSound(void) const;
};

#endif