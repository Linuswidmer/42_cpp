#ifndef SINGLETON_HPP
# define SINGELETON_HPP

# include <iostream>

class Singleton
{
public:
    // delete the assignment operator as well
    static Singleton& get(void) 
    {
        static Singleton S_Instance;
        return (S_Instance);
    };

    static float Float(void) {return(get().FloatImpl());};

private:
    Singleton(const Singleton&); // prevents another instance
    
    float   FloatImpl(void) {return (_random_number);};
    Singleton(void){}; // prevents another instance
    const static float   _random_number = 0.5;
};

#endif