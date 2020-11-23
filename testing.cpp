//
// Created by andrew hollar on 4/19/18.
//

#include <iostream>
#include "playerClass.h"
#include "menu.h"
#include "save.h"
#include "load.h"

using namespace std;

void testPlayerClass();
void testSaveLoad();
bool printMenuMethods();
void testSaveLoad();

//int main() {
//
//    testPlayerClass();
//    printMenuMethods();
//    testSaveLoad();
//    return 0;
//}

bool printMenuMethods(){
    Menu m;
    m.drawPauseMenu();
    m.drawStartMenu();
    m.drawEndScreen();
    return true;
}

void testPlayerClass() {
    playerClass p1 = playerClass();
    playerClass p2 = playerClass(20, 20);
    playerClass p3 = playerClass(30, 30, 45);
    cout << "Testing the default player" << endl;
    cout << p1.getX() << endl; //10
    cout << p1.getY() << endl; //10
    cout << p1.getScore() << endl; //0
    cout << "Testing the player with specified x and y coordinates" << endl;
    cout << p2.getX() << endl; //20
    cout << p2.getY() << endl; //20
    cout << p2.getScore() << endl; //0
    cout << "Testing the player with specified x, y, and score." << endl;
    cout << p3.getX() << endl; // 30
    cout << p3.getY() << endl; // 30
    cout << p3.getScore() << endl; //45
    cout << "Testing the move() function" << endl;
    p1.move(100, 100);
    //Player moved down
    cout << p1.getX() << endl; //100
    cout << p1.getY() << endl; //100
    cout << "Testing the jump() function." << endl;
    p1.jump();
    cout << p1.getY() << endl; //125
    cout << "Testing the addScore function" << endl;
    p1.addScore();
    cout << p1.getScore() << endl; //5
    cout << "Testing the resetScore function" << endl;
    p1.resetScore();
    cout << p1.getScore() << endl;
}

void testSaveLoad() {
    //testing save
    int score = 112315;
    Save a;
    a.saveScore(score);
    //testing load
    load b;
    int loadedScore = b.loadScore();
    cout << loadedScore;
}
