#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>
using namespace std;

class Brain {
private:
    static const size_t _n_ideas = 100; 
    std::string         _ideas[_n_ideas];
    size_t              _index_ideas;

public:
    Brain(void);
    Brain(const Brain& copy);
    Brain& operator=(const Brain& other);
    ~Brain(void);

    const std::string   getIdea(size_t i) const;
    void                setIdea(const std::string idea);
    size_t              index_ideas(void) const;
};

#endif