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
        if(isWayBlocked()== true){

        }
        else{
            if(this->direction==1){
                this->position.second=this->position.second+1;
            }
            if(this->direction==2){
                this->position.first=this->position.first+1;
            }
            if(this->direction==3){
                this->position.second=this->position.second-1;
            }
            if(this->direction==4){
                this->position.first=this->position.first-1;
            }

        }
    }
    bool isWayBlocked() override{
        if(this->position.first==0 && this->position.second<=8){
            return true;
        }
        if(this->position.first>=8 && this->position.second==0){
            return true;
        }
        if(this->position.first==8 && this->position.second>=8){
            return true;
        }
        if(this->position.first>=8 && this->position.second==8){
            return true;
        }
        return false;
    };
};


#endif //BUG_LIFE_PROJECT_HOPPER_H
