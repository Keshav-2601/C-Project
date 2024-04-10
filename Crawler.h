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

    void move() override ;
bool isWayBlocked() override ;

};


#endif //BUG_LIFE_PROJECT_CRAWLER_H
