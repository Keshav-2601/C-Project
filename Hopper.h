//
// Created by Keshav on 23/03/2024.
//

#ifndef BUG_LIFE_PROJECT_HOPPER_H
#define BUG_LIFE_PROJECT_HOPPER_H


#include "Bug.h"

class Hopper: public Bug {
public:
    int length;//length means the lenagth hopper can hop to .
    Hopper(int id,pair<int,int>position,int direction,int lenght){
        this->id=id;
        this->position=position;
        this->direction=direction;
        this->length=length;
    }
    void move() override{

    }
    bool isWayBlocked() override{

    };
};


#endif //BUG_LIFE_PROJECT_HOPPER_H
