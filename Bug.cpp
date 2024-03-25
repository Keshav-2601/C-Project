//
// Created by Keshav on 23/03/2024.
//

#include "Bug.h"
#include <iostream>

using namespace std;
//Bug::Bug(int id,int direction,int size,bool alive){
//    this->id=id;
//    this->direction=direction;
//    this->size=size;
//    this->alive=alive;
//}
Bug::Bug() {

}

 void Bug::show() {
     cout<<"Id:"<<this->id<<endl;
     cout<<"co-rodinates:{"<<this->position.first<<","<<this->position.second<<"}"<<endl;
     if(this->direction==1){
         cout<<"direction:"<<"North"<<endl;
     }
     if(this->direction==2){
         cout<<"direction:"<<"East"<<endl;
     }
     if(this->direction==3){
         cout<<"direction:"<<"South"<<endl;
     }
     if(this->direction==4){
         cout<<"direction:"<<"West"<<endl;
     }
     cout<<"size:"<<this->size<<endl;
     if(this->alive){
         cout<<"Status:"<<"Alive"<<endl;
     }
     if(!this->alive){
         cout<<"Status:"<< "Dead"<<endl;
     }

     cout<<endl;
}
int Bug::giveid() {
    return this->id;
}
void Bug::PathHistory() {
   for(auto i=path.begin(); i!=path.end();i++){
       cout<<this->id<<" "<<this->type<<" {"<<(*i).first<<","<<(*i).second<<"}"<<endl;
   }
}