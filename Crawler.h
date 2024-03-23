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

    };
    bool isWayBlocked() override {
        ;
    }
};


#endif //BUG_LIFE_PROJECT_CRAWLER_H
