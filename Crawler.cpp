//
// Created by Keshav on 23/03/2024.
//

#include "Crawler.h"

using namespace std;

void Crawler::showproperties()
    {
     cout<<"Id:"<<this->id<<endl;
     cout<<"x-position:"<<this->position.first<<endl;
     cout<<"y-position:"<<this->position.second<<endl;
     cout<<"direction:"<<this->direction<<endl;
     cout<<"size:"<<this->size;
    }