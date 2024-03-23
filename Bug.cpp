//
// Created by Keshav on 23/03/2024.
//

#include "Bug.h"
using namespace std;
Bug::Bug(int id,int direction,int size,bool alive){
    this->id=id;
    this->direction=direction;
    this->size=size;
    this->alive=alive;
}