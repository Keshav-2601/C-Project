
///
#include <iostream>
#include <fstream>
#include<string>
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"
#include "NewBugType.h"
#include<vector>
#include <iterator>
#include <sstream>


using namespace std;

int main() {
    ifstream inFile("../C.txt");
    if (!inFile) {
        cout << "Not able to open file";
        return 1;
    }

    // Load data from file and initialize Bug Board
    string line;
    vector<Bug*> bug_vector;
    while (getline(inFile, line)) {
        vector<string>parts;
        stringstream ss(line);//u make entire line in ss stream
        string singlepart;//then u break each string and store it in different string name singlestring

        while(getline(ss,singlepart,';')) {//use for slicing the string using delimiter ";".
            parts.push_back(singlepart);
        }
        if (parts[0] == "C") {
            Crawler *c1 = new Crawler(parts[0],stoi(parts[1]), {stoi(parts[2]), stoi(parts[3])}, stoi(parts[4]),
                                      stoi(parts[5]));
            bug_vector.push_back(c1);
            //storing memory in heap becoz if I store it on stack it will detroyed after each iteration so use DMA
        }
        if (parts[0] == "H") {
            Hopper *h1 = new Hopper(parts[0],stoi(parts[1]), {stoi(parts[2]), stoi(parts[3])}, stoi(parts[4]),
                                    stoi(parts[5]), stoi(parts[6]));
            bug_vector.push_back(h1);
        }
    }

    Board b1(10, 10); // Create a Board object with dimensions 10x10
    for(vector<Bug*>::iterator i=bug_vector.begin(); i != bug_vector.end(); i++){
        b1.addbug(*i);
    }
    int choice;
    do {
        // Display menu
        cout << "\nMenu Items\n"
             << "1. Display all Bugs\n"
             << "2. Find a Bug (given an id)\n"
             << "3. Tap the Bug Board (causes move all, then fight/eat)\n"
             << "4. Display Life History of all Bugs (path taken)\n"
             << "5. Display all Cells listing their Bugs\n"
             << "6. Run simulation (generates a Tap every second)\n"
             << "7. Exit (write Life History of all Bugs to file)\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Display all Bugs
                b1.showbug();
                break;
            case 2:
                // Find a Bug
                cout << b1.findbug() << endl;
                break;
            case 3:
                // Tap the Bug Board
                b1.TapBoard();
                break;
            case 4:
                // Display Bug History of all Bugs
                b1.bug_history();
                break;
            case 5:
                // Display all Cells listing their Bugs
                b1.display_all_cells();
                break;
            case 6:

                break;
            case 7: {
                ofstream outFile("bugs_life_history_date_time.out");
                if (!outFile) {
                    cerr << "unable to open output file" << endl;
                    return 1;
                }
                b1.LifeHistory(outFile);
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }
    } while (choice != 7); // Continue the loop until user chooses to exit

    // Clean up dynamically allocated memory
    for (Bug* bug : bug_vector) {
        delete bug;
    }
    return 0;
}
