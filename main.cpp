#include <iostream>
#include <fstream>
#include<string>
#include "Crawler.h"
#include "Hopper.h"
#include<vector>
#include <iterator>
using namespace std;

int main() {
ifstream inFile("../C.txt");//use ../C.txt to make it work;
if(inFile){
    string line;
    vector<Bug*> bugs;
   while(getline(inFile,line)){
          char ch=line.at(0);
          string str_id=line.substr(2,3);
          string str_pos1=line.substr(6,1);
          string str_pos2=line.substr(8,1);
          string str_dir=line.substr(10,1);
          string str_len=line.substr(12,1);
          if(ch=='C'){
              Crawler* c1=new Crawler(stoi(str_id),{stoi(str_pos1),stoi(str_pos2)},stoi(str_dir), stoi(str_len));
              bugs.push_back(c1);
              //storing memory in heap becoz if I store it on stack it will detroyed after each iteration so use DMA
          }
          if(ch=='H'){
              Hopper* h1=new Hopper(stoi(str_id),{stoi(str_pos1),stoi(str_pos2)},stoi(str_dir), stoi(str_len));
              bugs.push_back(h1);
          }


    }
    for(vector<Bug*>::iterator i=bugs.begin();i!=bugs.end();i++){

    }
}
else{
    cout<<"Not able to open file";
}
return 0;
}
