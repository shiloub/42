#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP
#include "ATarget.hpp"
#include <string>
#include <map>

class ATarget;


class TargetGenerator
{
    private :
        std::map<std::string, ATarget *> _targetbook;
        TargetGenerator(const TargetGenerator &cpy);
        TargetGenerator &operator=(const TargetGenerator &rhs);
    
    public :
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget*);
    void forgetTargetType(std::string const &);
    ATarget* createTarget(std::string const &);

};
#endif