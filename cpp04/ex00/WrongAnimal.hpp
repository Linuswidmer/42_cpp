#ifndef WRONG_WrongAnimal_HPP
# define WRONG_WrongAnimal_HPP
# include <string>
# include <iostream>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal(void);
    virtual ~WrongAnimal(void);
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal& operator=(const WrongAnimal &other);

    std::string getType(void);
    void        makeSound(void) const;
};

#endif