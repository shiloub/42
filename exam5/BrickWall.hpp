#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP
#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public :
        ATarget *clone() const;
        BrickWall();
        ~BrickWall();
};
#endif