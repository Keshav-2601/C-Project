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
    vector<Cell>cells;
    vector<Bug*>bugs;
public:
    Board(){

    }
    Board(int height,int width){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                Cell c1(i,j);
                cells.push_back(c1);
            }
        }
    }
    void addbug(Bug* bug){
        this->bugs.push_back(bug);
    }
    void showbug(){
        for(vector<Bug*>::iterator i=bugs.begin();i!=bugs.end();i++){
            (*i)->show();//deferenicng the *i to get **i ..we use -> .
        }
    }
     string findbug(){
        cout<<"enter the bug_id:"<<endl;
        int id;
        cin>>id;
        for(vector<Bug*>::iterator i=bugs.begin();i!=bugs.end();i++){
            if(id==(*i)->giveid()){
                cout<< "Id found Bug is:"<<endl;
                (*i)->show();
                 return "Found!!";
            }
        }
        cout<<"Bug Not Found!";
        return "Bug Not Found!";
    }
    void TapBoard(){
        for(vector<Bug*>::iterator i=bugs.begin();i!=bugs.end();i++){
            for(vector<Cell>::iterator j=cells.begin();j!=cells.end();j++){
                if((*i)->giveposition()==(*j).position_of_cell){
                    (*j).bug_occupying=*i;
                    (*j).isocupied=true;
                }
            }
        }
    }
    void display_all_cells(){
        for(vector<Bug*>::iterator i=bugs.begin();i!=bugs.end();i++){
            for(vector<Cell>::iterator j=cells.begin();j!=cells.end();j++){
                if((*i)->giveposition()==(*j).position_of_cell){
                    (*j).bug_occupying=*i;
                    (*j).isocupied=true;
                }
            }
        }
        for(vector<Cell>::iterator i=cells.begin();i!=cells.end();i++){
            if(!(*i).isocupied){
                cout<<"{"<<(*i).position_of_cell.first<<","<<(*i).position_of_cell.second<<"}: "<<"empty"<<endl;
            }
            if((*i).isocupied){
                cout<<"{"<<(*i).position_of_cell.first<<","<<(*i).position_of_cell.second<<"}:"<<((*i).bug_occupying)->typeofbug()<<endl;
            }
        }
    }
    void LifeHistory(){
        for(vector<Bug*>::iterator i=bugs.begin();i!=bugs.end();i++){
            (*i)->PathHistory();
            cout<<endl;
        }
    }
};


#endif //BUG_LIFE_PROJECT_BOARD_H
