#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal {
protected:
    std::string _type;

public:
    Animal(void);
    virtual ~Animal(void);
    Animal(const Animal &copy);
    Animal& operator=(const Animal &other);

    std::string     getType(void);
    virtual void    makeSound(void) const;
};

#endif