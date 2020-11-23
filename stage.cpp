//
// Created by Max on 4/17/2018.
//

#include "stage.h"

Stage::Stage() : x(0), y(0), xln(0), yln(0) {
    //draw();
}

Stage::~Stage() {
    // do nothing
}

void Stage::setX(int n) {
    x = n;
}

void Stage::setY(int n) {
    y = n;
}

int Stage::getX() const {
    return x;
}

int Stage::getY() const {
    return y;
}

//void Stage::draw();