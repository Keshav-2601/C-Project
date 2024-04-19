//
// Created by Keshav on 24/03/2024.
//

#ifndef BUG_LIFE_PROJECT_BOARD_H
#define BUG_LIFE_PROJECT_BOARD_H
#include "Cell.h"
#include "NewBugType.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
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
            (*i)->performedmove();
        }
    }
    void display_all_cells(){

        for(vector<Cell>::iterator i=cells.begin();i!=cells.end();i++){
            for(vector<Bug*>::iterator j=bugs.begin();j!=bugs.end();j++){
                if((*j)->giveposition()==(*i).position_of_cell){
                    (*i).bug_occupying.push_back(*j);
                    (*i).isocupied=true;
                }
            }
        }
        for(vector<Cell>::iterator i=cells.begin();i!=cells.end();i++){
            if(!(*i).isocupied){
                cout<<"{"<<(*i).position_of_cell.first<<","<<(*i).position_of_cell.second<<"}: "<<"empty"<<endl;
            }
            if((*i).isocupied){
                for(int j=0;j<(*i).bug_occupying.size();j++){
                    cout<<"{"<<(*i).position_of_cell.first<<","<<(*i).position_of_cell.second<<"}:"<<" "<<((*i).bug_occupying)[j]->typeofbug()<<" "<<((*i).bug_occupying)[j]->ids()<<" "<<(*i).bug_occupying[j]->givedirection()<<" "<<((*i).bug_occupying)[j]->getsizeofbug()<<endl;
                }
            }
        }
    }
    void eat_functionality() {
         for(vector<Cell>::iterator i=cells.begin();i!=cells.end();i++){
             if((*i).isocupied){
                 Bug* Winnerbug=(*i).bug_occupying[0];//max sized Bug
                 vector<Bug*>restBugs;//Have all the rest bugs other than Max sized one.
                 for(int j=1; j<(*i).bug_occupying.size();j++){
                     if(Winnerbug->getsizeofbug() < (*i).bug_occupying[j]->getsizeofbug()){
                         Winnerbug=(*i).bug_occupying[j];
                     }
                     else{
                         restBugs.push_back((*i).bug_occupying[j]);
                     }
                 }
                 //I will remove/erase that Winnerbug from orginal vectors list
                 for(vector<Bug*>::iterator i=restBugs.begin();i!=restBugs.end();i++){
                     vector<Bug*>::iterator removebug= find(bugs.begin(), bugs.end(),*i);//Basically removebug will be the vectro<Bug*>type iterator .find gives us iterator in return .
                     if(removebug!=bugs.end()){
                         bugs.erase(removebug);
                     }
                     for(vector<Bug*>::iterator j=bugs.begin();j!=bugs.end();j++){
                         if(Winnerbug==*j){
                             int sizeofwinnerbug=(*j)->getsizeofbug();
                             int sizeofloserbug=(*i)->getsizeofbug();
                             int Finalsize=sizeofwinnerbug+sizeofloserbug;
                             (*j)->winnerbugsize(Finalsize);
                         }
                     }
                     (*i)->eaten_bug();
                 }

             }

         }
    }

    void makingnewbug(){
        int id;
        int size;
        int direction;
        string type;
        pair<int,int>pos;
        cout<<"enter first position:"<<endl;
        cin>>pos.first;
        cout<<"enter second position:"<<endl;
        cin>>pos.second;
        cout<<"enter Id:"<<endl;
        cin>>id;
        cout<<"enter size:"<<endl;
        cin>>size;
        cout<<"enter initial direction:"<<endl;
        cin>> direction;
        cout<<"enter type:"<<endl;
        cin>>type;

         NewBugType *n1=new NewBugType(type,id,pos,direction,size);

         //making it a part of bug vector list
         bugs.push_back(n1);

    }

    void bug_history(){
        for(vector<Bug*>::iterator i=bugs.begin();i!=bugs.end();i++){
            (*i)->initial_path_history();
            cout<<endl;
        }
    }
    void LifeHistory(ofstream& outFile){
        for(vector<Bug*>::iterator i=bugs.begin();i!=bugs.end();i++){
            (*i)->PathHistory(outFile);
            outFile<<endl;
        }
    }
};


#endif //BUG_LIFE_PROJECT_BOARD_H
