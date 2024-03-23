//
// Created by Keshav on 23/03/2024.
//

#include "Crawler.h"

using namespace std;

Crawler::Crawler(int id, pair<int, int> position, int direction, int size, bool alive) {
    this->id=id;
    this->direction=direction;
    this->position=position;
    this->size=size;
    this->alive=alive;
}
void Crawler::move() {

}