#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>
using namespace std;

class Brain {
private:
    static const size_t _n_ideas = 100; 
    string              _ideas[_n_ideas];

public:
    Brain(void);
    Brain(const Brain& copy);
    Brain& operator=(const Brain& other);
    ~Brain(void);

    string  getIdea(void) const;
    void    setIdea(const string idea);
};

#endif