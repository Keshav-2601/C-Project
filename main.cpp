#include <iostream>
#include <fstream>
#include<string>
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"
#include<vector>
#include <iterator>
#include <sstream>


using namespace std;

int main() {
ifstream inFile("../C.txt");//use ../C.txt to make it work;
if(inFile){
    string line;

    vector<Bug*> bugs;
   while(getline(inFile,line)){
            vector<string>parts;
            stringstream ss(line);//u make entire line in ss stream
            string singlepart;//then u break each string and store it in different string name singlestring

            while(getline(ss,singlepart,';')) {//use for slicing the string using delimiter ";".
                parts.push_back(singlepart);
            }
            if (parts[0] == "C") {
                    Crawler *c1 = new Crawler(stoi(parts[1]), {stoi(parts[2]), stoi(parts[3])}, stoi(parts[4]),
                                              stoi(parts[5]));
                    bugs.push_back(c1);
                    //storing memory in heap becoz if I store it on stack it will detroyed after each iteration so use DMA
                }
            if (parts[0] == "H") {
                    Hopper *h1 = new Hopper(stoi(parts[1]), {stoi(parts[2]), stoi(parts[3])}, stoi(parts[4]),
                                            stoi(parts[5]), stoi(parts[6]));
                    bugs.push_back(h1);
                }

    }
    Board b1;//create a board object
    //iterating iver vector<Bug*>bugs and adding it into vector <Bug*>bugs of board class.
    for(vector<Bug*>::iterator i=bugs.begin();i!=bugs.end();i++){
        b1.addbug(*i);
    }
    //b1.showbug();
    //  b1.findbug();
    b1.TapBoard();

}
else{
    cout<<"Not able to open file";
}
return 0;
}
