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
    int length;//length means the lenagth hopper can hop to .
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
    void move() override{
        if(isWayBlocked()== true){
            int dir;
            if(this->direction==1 ||this->direction==2||this->direction==3||this->direction==4){
                do {
                    dir=rand()%4+1;
                }while(this->direction==dir);
                this->direction=dir;
            }

        }
        else{
            if(this->direction==1){
                path.push_back(this->position);
                this->position.second=this->position.second+this->length;
                path.push_back(this->position);
            }
            if(this->direction==2){
                path.push_back(this->position);
                this->position.first=this->position.first+this->length;
                path.push_back(this->position);
            }
            if(this->direction==3){
                path.push_back(this->position);
                this->position.second=this->position.second-this->length;
                path.push_back(this->position);
            }
            if(this->direction==4){
                path.push_back(this->position);
                this->position.first=this->position.first-this->length;
                path.push_back(this->position);
            }

        }
    }
    bool isWayBlocked() override{
        if(this->position.first==0 && this->position.second<=8 && this->direction==3){
            return true;
        }
        if(this->position.first>=8 && this->position.second==0 && this->direction==4){
            return true;
        }
        if(this->position.first==8 && this->position.second>=8 && this->direction==2){
            return true;
        }
        if(this->position.first>=8 && this->position.second==8 && this->direction==1){
            return true;
        }
        return false;
    };
};


#endif //BUG_LIFE_PROJECT_HOPPER_H
