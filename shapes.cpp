#include "graphics.h"
#include "shapes.h"
#include <cmath>

/******************** point struct ********************/

point::point() : x(0), y(0) { }

point::point(int xIn, int yIn) : x(xIn), y(yIn) { }

/******************** Shape class ********************/

Shape::Shape() : area(0), perimeter(0),
                 center({0, 0}), fill({0, 0, 0}) {
    // color defaults to black
}

Shape::Shape(point c, color f) : area(0), perimeter(0),
                                 center(c), fill(f) { }

Shape::Shape(int xIn, int yIn, double r, double g, double b) :
        area(0), perimeter(0), center({xIn, yIn}), fill({r, g, b}) { }

double Shape::getArea() const {
    return area;
}

double Shape::getPerimeter() const {
    return perimeter;
}

color Shape::getFill() const {
    return fill;
}

void Shape::setPoint(point c) {
    center = c;
}

void Shape::setPoint(int xIn, int yIn) {
    center = {xIn, yIn};
}

void Shape::move(int deltaX, int deltaY) {
    center.x += deltaX;
    center.y += deltaY;
}

void Shape::setColor(color f) {
    fill = f;
}

void Shape::setColor(double r, double g, double b) {
    fill = {r, g, b};
}

/******************** Rect class ********************/

void Rect::calculateArea() {
    area = length * width;
}

void Rect::calculatePerimeter() {
    perimeter = 2.0 * length + 2.0 * width;
}

Rect::Rect() : Shape(), length(0), width(0) { }

Rect::Rect(double l, double w) : Shape() {
    setDimensions(l, w);
}

double Rect::getLength() const {
    return length;
}

double Rect::getWidth() const {
    return width;
}

point Shape::getCenter() const {
    return center;
}

double Rect::getX() const {
    return center.x;
}

double Rect::getY() const {
    return center.y;
}

void Rect::setDimensions(double l, double w) {
    // we do not want to accept negative values
    // for length and width
    length = (l < 0) ? 0 : l;
    width = (w < 0) ? 0 : w;
    // now update area and perimeter
    calculateArea();
    calculatePerimeter();
}

void Rect::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(length/2.0));
    // top right
    glVertex2i(center.x+(width/2.0), center.y-(length/2.0));
    // bottom right
    glVertex2i(center.x+(width/2.0), center.y+(length/2.0));
    // bottom left
    glVertex2i(center.x-(width/2.0), center.y+(length/2.0));
    glEnd();
}






