#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog: public Animal {
private:

public:
    Dog(void);
    ~Dog(void);
    Dog(const Dog& copy);
    Dog& operator=(const Dog& other);

    void    makeSound(void) const; // override
};

#endif