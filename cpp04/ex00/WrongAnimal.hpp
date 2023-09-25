#ifndef WRONG_WrongAnimal_HPP
# define WRONG_WrongAnimal_HPP
# include <string>
# include <iostream>
using namespace std;

class WrongAnimal {
protected:
    string _type;

public:
    WrongAnimal(void);
    virtual ~WrongAnimal(void);
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal& operator=(const WrongAnimal &other);

    string  getType(void);
    void    makeSound(void) const;
};

#endif