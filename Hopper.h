//
// Created by Keshav on 23/03/2024.
//

#ifndef BUG_LIFE_PROJECT_HOPPER_H
#define BUG_LIFE_PROJECT_HOPPER_H


#include <cstdlib>
#include <ctime>
#include <string>
#include "Bug.h"

class Hopper: public Bug {
private:
    int length;//length means the length hopper can hop to .
public:

    Hopper(string type,int id,pair<int,int>position,int direction,int size,int length){
        this->type=type;
        this->id=id;
        this->position=position;
        this->direction=direction;
        this->size=size;
        this->length=length;
        srand(time(0));
    }
    void move() override;

    bool isWayBlocked() override;

};


#endif //BUG_LIFE_PROJECT_HOPPER_H
