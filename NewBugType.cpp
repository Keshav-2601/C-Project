//
// Created by Keshav on 10/04/2024.
//

#include "NewBugType.h"
void NewBugType::move() {
    if(isWayBlocked()){
        int dir;
        if(this->direction==1 ||this->direction==2||this->direction==3||this->direction==4){
            do {
                dir=rand()%4+1;
            }while(this->direction==dir);
            this->direction=dir;
        }
    }
    else{
        if(this->direction==1){
            this->path.push_back(this->position);
            this->position.first=this->position.first+1;
            this->position.second=this->position.second+1;
            this->path.push_back(this->position);
        }
        if(this->direction==2){
            this->path.push_back(this->position);
            this->position.first=this->position.first+1;
            this->position.second=this->position.second-1;
            this->path.push_back(this->position);
        }
        if(this->direction==3){
            this->path.push_back(this->position);
            this->position.first=this->position.first-1;
            this->position.second=this->position.second-1;
            this->path.push_back(this->position);
        }
        if(this->direction==4){
            this->path.push_back(this->position);
            this->position.first=this->position.first-1;
            this->position.second=this->position.second+1;
            this->path.push_back(this->position);
        }
    }
}
bool NewBugType::isWayBlocked() {
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