//
// Created by Keshav on 23/03/2024.
//

#ifndef BUG_LIFE_PROJECT_CRAWLER_H
#define BUG_LIFE_PROJECT_CRAWLER_H

#include "Bug.h";
class Crawler: public Bug {
public:

    void move() override =0;
    bool isWayBlocked() override =0;
};


#endif //BUG_LIFE_PROJECT_CRAWLER_H