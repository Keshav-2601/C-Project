#include <iostream>
#include <fstream>
#include<string>
#include "Crawler.h"
#include "Hopper.h"
#include<vector>
using namespace std;

int main() {
ifstream inFile("../C.txt");//use ../C.txt to make it work;
if(inFile){
    string line;
    vector<Bug*> bugs;
   while(getline(inFile,line)){
          char ch=line.at(0);
          if(ch=='C'){
               Crawler* c1=new Crawler(line.at(1),{line.at(2),line.at(3)},line.at(4),line.at(5));
              bugs.push_back(c1);
              //storing memory in heap becoz if i store it on stack it will detroyed after each iteration so use DMA
          }
          if(ch=='H'){
              Hopper* h1=new Hopper(line.at(1),{line.at(2),line.at(3)},line.at(4),line.at(5));
              bugs.push_back(h1);
          }

          cout<<line<<endl;
    }
}
else{
    cout<<"Not able to open file";
}
}
