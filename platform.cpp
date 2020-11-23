//
// Created by andrew hollar on 4/25/18.
//

#include "platform.h"
using namespace std;


Platform::Platform() : Stage() {
    //v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
    platformDisplay.setDimensions(25, 150);
    platformDisplay.setColor(0.8, 0.1, 0.2);
    platformDisplay.setPoint(200, 0);
    hasBeenLandedOn = false;
}

Platform::Platform(int x) : Stage() {
    //v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
    platformDisplay.setDimensions(25, 150);
    platformDisplay.setColor(0.8, 0.1, 0.2);
    platformDisplay.setPoint(x, -25);                          //-25 means the platforms start off screen
    hasBeenLandedOn = false;

}

Platform::Platform(int x, int y) : Stage() {
    //v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
    platformDisplay.setDimensions(25, 150);
    platformDisplay.setColor(0.8, 0.1, 0.2);
    platformDisplay.setPoint(x, y);
    hasBeenLandedOn = false;
}

Platform::Platform(int x, int r, int g, int b) : Stage() {
    //v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
    platformDisplay.setDimensions(25, 150);
    platformDisplay.setColor(r, g, b);
    platformDisplay.setPoint(x, -25);
    hasBeenLandedOn = false;
}

Platform::Platform(int x, int y, int r, int g, int b) : Stage() {
    //v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
    platformDisplay.setDimensions(25, 150);
    platformDisplay.setColor(r, g, b);
    platformDisplay.setPoint(x, y);
    hasBeenLandedOn = false;
}

void Platform::setPlatformDisplay(Rect platform) {
    platformDisplay = platform;
}

Rect Platform::getPlatformDisplay() const {
    return platformDisplay;
}

void Platform::draw() {
    getPlatformDisplay().draw();
}

void Platform::move(int xIn, int yIn){

    //Set the new location of the player object
    //TEST//cout << "Platforms moved " << endl;
    this->x += xIn;
    this->y += yIn;
    platformDisplay.move(xIn, yIn);
}

bool Platform::isHasBeenLandedOn() const {
    return hasBeenLandedOn;
}

void Platform::setHasBeenLandedOn(bool hasBeenLandedOn) {
    Platform::hasBeenLandedOn = hasBeenLandedOn;
}
