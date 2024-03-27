//
// Created by Keshav on 23/03/2024.
//

#ifndef BUG_LIFE_PROJECT_CRAWLER_H
#define BUG_LIFE_PROJECT_CRAWLER_H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Bug.h"
using namespace std;
class Crawler: public Bug {
public:

    Crawler(string type,int id,pair<int,int> position,int direction,int size){
        this->type=type;
        this->id=id;
        this->direction=direction;
        this->position=position;
        this->size=size;
        srand(time(0));
    };
    void move() override {
        if(isWayBlocked()== true){
            int dir;
            if(this->direction==1 ||this->direction==2||this->direction==3||this->direction==4){
                do {
                    dir=rand()%4+1;
                }while(this->direction==dir);
                this->direction=dir;
                move();
            }

        }
        else{
             if(this->direction==1){
                  path.push_back(this->position);
                  this->position.second=this->position.second+1;
                  path.push_back(this->position);
              }
            if(this->direction==2){
                path.push_back(this->position);
                this->position.first=this->position.first+1;
                path.push_back(this->position);
            }
            if(this->direction==3){
                path.push_back(this->position);
                this->position.second=this->position.second-1;
                path.push_back(this->position);
            }
            if(this->direction==4){
                path.push_back(this->position);
                this->position.first=this->position.first-1;
                path.push_back(this->position);
            }

        }
    };
    bool isWayBlocked() override {
        if(this->position.first==0 && this->position.second<=9 && this->direction==3){
            return true;
        }
        if(this->position.first<=9 && this->position.second==0 && this->direction==4){
            return true;
        }
        if(this->position.first==9 && this->position.second>=9 && this->direction==2){
            return true;
        }
        if(this->position.first>=9 && this->position.second==9 && this->direction==1){
            return true;
        }
        return false;
    }

};


#endif //BUG_LIFE_PROJECT_CRAWLER_H
