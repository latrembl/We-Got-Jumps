//
// Created by Ben on 4/17/2018.
//
#include "iostream"
#include "playerClass.h"

using namespace std;

//Constructors
playerClass::playerClass() {
    playerIcon.setDimensions(25, 25);
    playerIcon.setColor(0.8, 0.1, 0.2);
    playerIcon.setPoint(x, y);
    score = 0;
    xVelocity = 0;
    yVelocity = 0;
    onStage = false;
    //deltaMovement = -5;
    this->x = 10;
    this->y = 10;
    //TESTcout << "Player object created" << endl;
}

playerClass::playerClass(int x, int y) {
    playerIcon.setDimensions(25, 25);
    playerIcon.setColor(0.8, 0.1, 0.2);
    playerIcon.setPoint(x, y);
    score = 0;
    xVelocity = 0;
    yVelocity = 0;
    onStage = false;
    //deltaMovement = -5;
    this->x = x;
    this->y = y;
}

playerClass::playerClass(int x, int y, int score){
    playerIcon.setDimensions(25, 25);
    playerIcon.setColor(0.8, 0.1, 0.2);
    playerIcon.setPoint(x, y);
    xVelocity = 0;
    yVelocity = 0;
    onStage = false;
    //deltaMovement = -5;
    this->x = x;
    this->y = y;
    this->score = score;
}

/*//Getters
int playerClass::getX() const{
    return x;
}

int playerClass::getY() const{
    return y;
}*/

int playerClass::getScore() const{
    return score;
}

//Setters
//void playerClass::setX(int x){
//    this->x = x;
//}
//
//void playerClass::setY(int y){
//    this->y = y;
//}

void playerClass::setScore(int score){
    this->score = score;
}

//Methods

void playerClass::move(int xIn, int yIn){
     //Set the new location of the player object
    //cout << "Player moved " << endl;
    this->x = xIn;
    this->y = yIn;
    playerIcon.move(xIn, yIn);
}

void playerClass::draw() {
    //Draw the rectangle/ square for the player object
    //cout << "Player object drawn" << endl;
    playerIcon.draw();
}

void playerClass::jump(){
    //Increase the y and then reset the y to the base value for the player object
    //TEST//cout << "Player jumped" << endl;
    setOnStage(false);
    setYVelocity(-95);
    setYVelocity(-120);
}

void playerClass::addScore(){
    //Add one to the score
    score += 10;
}

void playerClass::resetScore(){
    score = 0;
}

const Rect &playerClass::getPlayerIcon() const {
    return playerIcon;
}

void playerClass::setPlayerIcon(const Rect &playerIcon) {
    playerClass::playerIcon = playerIcon;
}
//
//int playerClass::getDeltaMovement() const {
//    return deltaMovement;
//}
//
//void playerClass::setDeltaMovement(int deltaMovement) {
//    playerClass::deltaMovement = deltaMovement;
//}

int playerClass::getXVelocity() const {
    return xVelocity;
}

void playerClass::setXVelocity(int xVelocity) {
    playerClass::xVelocity = xVelocity;
}

int playerClass::getYVelocity() const {
    return yVelocity;
}

void playerClass::setYVelocity(int yVelocity) {
    playerClass::yVelocity = yVelocity;
}

bool playerClass::isOnStage() const {
    return onStage;
}

void playerClass::setOnStage(bool onStage) {
    playerClass::onStage = onStage;
}
