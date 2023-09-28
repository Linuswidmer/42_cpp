#ifndef ICE_HPP
# define ICE_HPP

# include "header.h"

class Ice: public AMateria
{
private:

public:
    Ice(std::string const& type);
    Ice(const Ice& copy);
    Ice &operator=(const Ice& other);
    ~Ice(void);

    AMateria* clone() const;
    // virtual void use(ICharacter& target);
};

#endif