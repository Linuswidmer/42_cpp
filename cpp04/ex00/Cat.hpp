#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal {
private:

public:
    Cat(void);
    ~Cat(void);
    Cat(const Cat &copy);
    Cat& operator=(const Cat &other);

    void makeSound(void) const; // override
};

#endif