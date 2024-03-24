//
// Created by Keshav on 24/03/2024.
//

#ifndef BUG_LIFE_PROJECT_CELL_H
#define BUG_LIFE_PROJECT_CELL_H

#include <utility>
#include "Bug.h"

using namespace std;
class Cell {
public:
    pair<int,int>position_of_cell;
    bool isocupied;
    Bug* bug_occupying;

    Cell(int x,int y){
        position_of_cell={x,y};
        this->isocupied=false;
        this->bug_occupying= nullptr;
    }

};


#endif //BUG_LIFE_PROJECT_CELL_H
