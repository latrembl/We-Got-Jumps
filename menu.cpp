//
// Created by Ben on 4/17/2018.
//
#include "iostream"
#include "menu.h"
#include "graphics.h"
#include "shapes.h"

using namespace std;


Menu::Menu() {}

void Menu::drawText(string m,int font, double r,double g,double b,int xIn, int yIn) {
    string message = m;
    int fontType = font;
    double red = r;
    double green = g;
    double blue = b;
    int x = xIn;
    int y = yIn;

    switch(fontType){
        case 1 :
            glColor3f(red,green,blue);
            glRasterPos2i(x,y);
            for (char a : message) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, a);
            } break;
        case 2 :
            glColor3f(red,green,blue);
            glRasterPos2i(x,y);
            for (char b : message) {
                glutBitmapCharacter(GLUT_BITMAP_9_BY_15, b);
            } break;
        case 3 :
            glColor3f(red,green,blue);
            glRasterPos2i(x,y);
            for (char c : message) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, c);
            } break;
        case 4 :
            glColor3f(red,green,blue);
            glRasterPos2i(x,y);
            for (char d : message) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, d);
            } break;
        case 5 :
            glColor3f(red,green,blue);
            glRasterPos2i(x,y);
            for (char e : message) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, e);
            } break;
        case 6 :
            glColor3f(red,green,blue);
            glRasterPos2i(x,y);
            for (char f : message) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, f);
            } break;
        case 7 :
            glColor3f(red,green,blue);
            glRasterPos2i(x,y);
            for (char g : message) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, g);
            } break;
    }
}

void Menu::drawStartMenu() const {
    //Display start menu
    //TEST//cout << menu << " Start Menu Displayed " << endl;
    Rect pauseBox1,pauseBox2;
    pauseBox1.setDimensions(495,375);
    pauseBox1.setColor(0.8, 0.1, 0.2);
    pauseBox1.setPoint(600,400);
    pauseBox2.setDimensions(490,370);
    pauseBox2.setColor(0,0,0);
    pauseBox2.setPoint(600,400);
    pauseBox1.draw();
    pauseBox2.draw();
    Menu().drawText("STAY ON THE PLATFORMS!",2,0.8, 0.1, 0.2,500,200);              //red
    Menu().drawText("USE ARROW KEYS TO MOVE",2,0.1, 0.1, 0.7,500,300);              //blue
    Menu().drawText("PRESS SPACEBAR TO JUMP",2,0.1, 0.1, 0.7,500,400);              //blue
    Menu().drawText("PRESS 'L' TO LOAD GAME",2,1,1,0.5,500,500);                    //yellow
    Menu().drawText("CLICK ANYWHERE TO BEGIN",2,0,1,0,500,600);                     //yellow
}

void Menu::drawPauseMenu() const{
    //Display the pause menu
    //TEST//cout << menu << " " <<resume << " Menu Paused" << endl;
    Rect pauseBox1,pauseBox2;
    pauseBox1.setDimensions(60,245);
    pauseBox1.setColor(0.8, 0.1, 0.2);
    pauseBox1.setPoint(590,395);
    pauseBox2.setDimensions(55,240);
    pauseBox2.setColor(0,0,0);
    pauseBox2.setPoint(590,395);
    pauseBox1.draw();
    pauseBox2.draw();
    Menu().drawText("PRESS 'P' TO UNPAUSE",2,0.8, 0.1, 0.2,500,400);                 //red
}

void Menu::drawEndScreen() const {
    //Display the game over menu
    //TEST//cout << gameOver << endl;
    Rect pauseBox1,pauseBox2;
    pauseBox1.setDimensions(60,245);
    pauseBox1.setColor(0.8, 0.1, 0.2);
    pauseBox1.setPoint(590,395);
    pauseBox2.setDimensions(55,240);
    pauseBox2.setColor(0,0,0);
    pauseBox2.setPoint(590,395);
    pauseBox1.draw();
    pauseBox2.draw();
    Menu().drawText("GAME OVER",2,0.8, 0.1, 0.2,550,400);             //red
    Menu().drawText("'S' TO SAVE GAME",2,0,0,0,20,400);               //write over previous message in black to cover it
    Menu().drawText("CANNOT SAVE",2,0.8, 0.1, 0.2,20,400);            //red
    Menu().drawText("'P' TO PAUSE",2,0,0,0,20,300);                   //write over previous message in black to cover it
    Menu().drawText("CANNOT PAUSE",2,0.8, 0.1, 0.2,20,300);           //red
}

void Menu::drawScreenMenu() const {
    Menu().drawText("RIGHT CLICK TO RESTART",2,0.1, 0.1, 0.7,20,200);   //blue
    Menu().drawText("'P' TO PAUSE",2,1,1,0.5,20,300);                   //yellow
    Menu().drawText("'S' TO SAVE GAME",2,1,1,0.5,20,400);               //yellow
    Menu().drawText("'L' TO LOAD GAME",2,1,1,0.5,20,500);               //yellow
}