#include "Hopper.h"

bool Hopper::isWayBlocked() {
    if (this->direction == 1 && this->position.second + this->length > 9) {
        return true;
    }
    if (this->direction == 2 && this->position.first + this->length > 9) {
        return true;
    }
    if (this->direction == 3 && this->position.second - this->length < 0) {
        return true;
    }
    if (this->direction == 4 && this->position.first - this->length < 0) {
        return true;
    }
    return false;
}

void Hopper::move() {
    srand(time(0));
    path.clear();

    if (isWayBlocked()) {
        int dir;
        do {
            dir = rand() % 4 + 1;
        } while (this->direction == dir);
        this->direction = dir;
    }
    else {
        if (this->direction == 1) {
            path.push_back(this->position);
            this->position.second += this->length;
            path.push_back(this->position);
        }
        else if (this->direction == 2) {
            path.push_back(this->position);
            this->position.first += this->length;
            path.push_back(this->position);
        }
        else if (this->direction == 3) {
            path.push_back(this->position);
            this->position.second -= this->length;
            path.push_back(this->position);
        }
        else if (this->direction == 4) {
            path.push_back(this->position);
            this->position.first -= this->length;
            path.push_back(this->position);
        }
    }
}
