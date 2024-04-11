//
// Created by Keshav on 10/04/2024.
//

#ifndef BUG_LIFE_PROJECT_NEWBUGTYPE_H
#define BUG_LIFE_PROJECT_NEWBUGTYPE_H


#include "Bug.h"

class NewBugType: public Bug{
public:
    NewBugType(string type,int id, pair<int,int> pos, int direction,int size){
        this->type=type;
        this->id=id;
        this->position=pos;
        this->direction=direction;
        this->size=size;

    }
   //method from Bug class
    void move() override;//will move in right diagonal.
    bool isWayBlocked() override;
};


#endif //BUG_LIFE_PROJECT_NEWBUGTYPE_H
