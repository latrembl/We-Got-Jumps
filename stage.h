//
// Created by Max on 4/17/2018.
//

#ifndef JUMPS_JUMPS_H
#define JUMPS_JUMPS_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include "graphics.h"
using namespace std;

/**
 * Stage class to store food object
 */
class Stage {
protected:
    int xln;
    int yln;
    int x;
    int y;

public:
    /**
     * Default Constructor
     * Requires: nothing
     * Modifies: nothing
     * Effects: draws the stage
    */
    Stage();

    /**
     * Destructor
     * Requires: nothing
     * Modifies: nothing
     * Effects: does nothing
    */
    ~Stage();

    /**
     * X Setter
     * Requires: nothing
     * Modifies: taste
     * Effects: sets x to n
    */
    void setX(int n);

    /**
     * Y Setter
     * Requires: nothing
     * Modifies: taste
     * Effects: sets y to n
    */
    void setY(int n);

    /**
     * X Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the x
    */
    int getX() const;

    /**
     * Y Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the y
    */
    int getY() const;

    /**
     * Draw Method
     * Requires: nothing
     * Modifies: nothing
     * Effects: draws the stage
    */
    virtual void draw() = 0;

    void drawText(string m,int font, double r,double g,double b,int xIn, int yIn) {
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
};

#endif //JUMPS_JUMPS_H
