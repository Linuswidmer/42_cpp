#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
using namespace std;

class Brain {
private:
    string ideas[100];

public:
    Brain(void);
    Brain(const Brain& copy);
    Brain& operator=(const Brain& other);
    ~Brain(void);
};

#endif