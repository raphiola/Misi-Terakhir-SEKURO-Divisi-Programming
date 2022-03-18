#ifndef robot_hpp
#define robot_hpp

#include <iostream>
#include <cstdio>
#include "axis.h"

using namespace std;

class robot
{
    public:
    	int health;
        int power;
        double range;
        axis position;
        robot();
        robot(char k, axis a);
        void moverobot(axis a);
        bool isalive();
};

#endif
