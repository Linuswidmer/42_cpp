#ifndef ICE_HPP
# define ICE_HPP

# include "header.h"

class Ice: public AMateria
{
public:
    Ice(void);
    Ice(const Ice& copy);
    Ice &operator=(const Ice& other);
    ~Ice(void);

    AMateria* clone() const; // override
    void use(ICharacter& target); //override
private:

};

#endif