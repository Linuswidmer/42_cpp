#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal {
private:
    Brain   *_brain;

public:
    Cat(void);
    ~Cat(void);
    Cat(const Cat &copy);
    Cat& operator=(const Cat &other);

    void makeSound(void) const;
    void newIdea(string idea);
    void tellIdea(void) const;
};

#endif