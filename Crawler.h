//
// Created by Keshav on 23/03/2024.
//

#ifndef BUG_LIFE_PROJECT_CRAWLER_H
#define BUG_LIFE_PROJECT_CRAWLER_H

#include "Bug.h"
class Crawler: public Bug {
public:
    int lenght;
    Crawler(int id,pair<int,int> position,int direction,int length){
        this->id=id;
        this->direction=direction;
        this->position=position;
        this->size=size;
        this->lenght=lenght;
    };
    void move() override {
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
    };
    bool isWayBlocked() override {
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
    }
};


#endif //BUG_LIFE_PROJECT_CRAWLER_H
