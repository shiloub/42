#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::TargetGenerator(const TargetGenerator &cpy){
    *this = cpy;
}
TargetGenerator::~TargetGenerator(){}
TargetGenerator &TargetGenerator::operator=(const TargetGenerator &rhs){
    this->_targetbook = rhs._targetbook;
    return (*this);
}
void    TargetGenerator::learnTargetType(ATarget *target)
{
    if (target)
        this->_targetbook[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
    this->_targetbook.erase(target);
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
    ATarget *tmp = NULL;
    if (this->_targetbook.find(target) != this->_targetbook.end())
        tmp = this->_targetbook[target];
    return (tmp);
}