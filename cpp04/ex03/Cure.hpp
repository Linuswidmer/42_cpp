#ifndef CURE_HPP
# define CURE_HPP

# include "header.h"

class Cure: public AMateria
{
public:
    Cure(void);
    Cure(const Ice& copy);
    Cure &operator=(const Ice& other);
    ~Cure(void);

    AMateria*   clone() const; // override
    void        use(ICharacter& target);
private:
};

#endif