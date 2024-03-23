#include <iostream>
#include <fstream>
#include<string>
using namespace std;

int main() {
ifstream inFile("../C.txt");//use ../C.txt to make it work;
if(inFile){
    string line;
    while(getline(inFile,line)){
           cout<<line<<endl;
    }
}
else{
    cout<<"Not able to open file";
}
}
