#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie
{
    public :
        Zombie();
        ~Zombie();
        Zombie(std::string s);
        void announce(void);
        
    private :
        std::string name;
};

#endif