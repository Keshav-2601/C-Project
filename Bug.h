//
// Created by Keshav on 23/03/2024.
//

#ifndef BUG_LIFE_PROJECT_BUG_H
#define BUG_LIFE_PROJECT_BUG_H

#include <list>
#include <utility>
#include <string>

using namespace std;
class Bug {
protected:
    string type;
    int id;
    int direction;
    pair<int, int> position;
    int size;
    bool alive= true;
    list<pair<int,int>>path;
    virtual void move()=0;
    virtual bool isWayBlocked()=0;
public:
    void performedmove(){
        move();
        isWayBlocked();
    }
    Bug();
//    Bug(int id,int direction,int size,bool alive);
    void show();
    int giveid();
    void PathHistory();
    pair<int,int> giveposition();
    string typeofbug();
    int ids();

    int getsizeofbug();
    bool alivestatus();
};


#endif //BUG_LIFE_PROJECT_BUG_H
