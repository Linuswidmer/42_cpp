#ifndef WRONG_WrongCat_HPP
# define WRONG_WrongCat_HPP
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
private:

public:
    WrongCat(void);
    ~WrongCat(void);
    WrongCat(const WrongCat &copy);
    WrongCat& operator=(const WrongCat &other);

    void makeSound(void) const;
};

#endif