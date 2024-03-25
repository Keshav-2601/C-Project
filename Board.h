//
// Created by Keshav on 24/03/2024.
//

#ifndef BUG_LIFE_PROJECT_BOARD_H
#define BUG_LIFE_PROJECT_BOARD_H
#include "Cell.h"
#include <vector>
#include <iostream>
using namespace std;
class Board {
private:
    vector<vector<Cell>>cells;
    vector<Bug*>bugs;
public:
    Board(){

    }
    Board(int height,int width){

    }
    void addbug(Bug* bug){
        this->bugs.push_back(bug);
    }
    void showbug(){
        for(vector<Bug*>::iterator i=bugs.begin();i!=bugs.end();i++){
            (*i)->show();//deferenicng the *i to get **i ..we use -> .
        }
    }
};


#endif //BUG_LIFE_PROJECT_BOARD_H
