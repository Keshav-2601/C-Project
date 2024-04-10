//
// Created by Keshav on 10/04/2024.
//

#ifndef BUG_LIFE_PROJECT_NEWBUGTYPE_H
#define BUG_LIFE_PROJECT_NEWBUGTYPE_H


#include "Bug.h"

class NewBugType: public Bug{
public:
    NewBugType(int size,int id,string type,bool isalive){
        this->size=size;
        this->id=id;
        this->type=type;
        this->alive=isalive;
    }
   //method from Bug class
    void move() override;//My newBug can walk 3 units in any directions regardless where it's face is facing
    bool isWayBlocked() override;
};


#endif //BUG_LIFE_PROJECT_NEWBUGTYPE_H
