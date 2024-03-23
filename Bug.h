//
// Created by Keshav on 23/03/2024.
//

#ifndef BUG_LIFE_PROJECT_BUG_H
#define BUG_LIFE_PROJECT_BUG_H

#include <list>
#include <utility>
using namespace std;
class Bug {
protected:
    int id;
    int direction;
    int size;
    bool alive;
    list<pair<int,int>>path;
    virtual void move()=0;
    virtual bool isWayBlocked()=0;
public:
    Bug(int id,int direction,int size,bool alive);
};


#endif //BUG_LIFE_PROJECT_BUG_H
