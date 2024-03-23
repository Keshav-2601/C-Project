//
// Created by Keshav on 23/03/2024.
//

#ifndef BUG_LIFE_PROJECT_HOPPER_H
#define BUG_LIFE_PROJECT_HOPPER_H


#include "Bug.h"

class Hopper: public Bug {
public:
    int length;//length means the lenagth hopper can hop to .
    void move() override=0;
    bool isWayBlocked() override=0;
};


#endif //BUG_LIFE_PROJECT_HOPPER_H
