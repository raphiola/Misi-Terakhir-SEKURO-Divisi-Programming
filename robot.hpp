#ifndef robot_hpp
#define robot_hpp

#include <iostream>
#include <cstdio>
#include "axis.h"

using namespace std;

class robot
{
    private:
        int health;
        int power;
        double range;
        axis position;

    public:
        robot();
};

#endif