#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog: public Animal {
private:
    Brain   *_brain;

public:
    Dog(void);
    ~Dog(void);
    Dog(const Dog& copy);
    Dog& operator=(const Dog& other);

    Brain *brain(void) const;
    void    makeSound(void) const;
    void    newIdea(std::string idea);
    void    tellIdea(void) const;
};

#endif