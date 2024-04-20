//
// Created by Keshav on 23/03/2024.
//

#include "Crawler.h"

using namespace std;

bool Crawler::isWayBlocked() {

    if (this->position.first == 0 && this->direction == 4) {
        return true;
    }
    if (this->position.first == 9 && this->direction == 2) {
        return true;
    }
    if (this->position.second == 0 && this->direction == 3) {
        return true;
    }
    if (this->position.second == 9 && this->direction == 1) {
        return true;
    }
    return false;
}

void Crawler::move() {
    srand(time(0));
    path.clear(); // Clear the path after every new tap

    if (isWayBlocked()) {
        int dir;
        do {
            dir = rand() % 4 + 1;
        } while (this->direction == dir);
        this->direction = dir;
    }
    else {
        path.push_back(this->position);
        if (this->direction == 1) {
            this->position.second++;
        } else if (this->direction == 2) {
            this->position.first++;
        } else if (this->direction == 3) {
            this->position.second--;
        } else if (this->direction == 4) {
            this->position.first--;
        }
        path.push_back(this->position);
    }
}
