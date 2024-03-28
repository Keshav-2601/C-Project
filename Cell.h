//
// Created by Keshav on 24/03/2024.
//

#ifndef BUG_LIFE_PROJECT_CELL_H
#define BUG_LIFE_PROJECT_CELL_H

#include <utility>
#include <vector>
#include "Bug.h"

using namespace std;
class Cell {
public:
    pair<int,int>position_of_cell;
    bool isocupied;
    vector<Bug*>bug_occupying;//give vector because one cell can be occupied by 2 or more bugs i cound have given array also it's ur choice

    Cell(int x,int y){
        position_of_cell={x,y};
        this->isocupied=false;

    }

};


#endif //BUG_LIFE_PROJECT_CELL_H
