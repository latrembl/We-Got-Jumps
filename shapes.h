
#ifndef FINALPROJECT120_SHAPES_H
#define FINALPROJECT120_SHAPES_H

const double PI = 3.14159265358979;

// colors in OpenGL are stored in three (r, g, b) values
// with each on a [0,1] scale
// e.g. salmon is (250, 128, 114), which we would store as
// (250/255.0, 128/255.0, 114/255.0)
struct color {
    double red;
    double green;
    double blue;
};

struct point {
    // these fields are public by default
    int x;
    int y;

    point();
    point(int xIn, int yIn);
};

// Note: a line is not considered a shape because it
//       does not have an area
// Note: this is an abstract class
class Shape {
public:
    // Constructors
    Shape();
    Shape(point c, color f);
    Shape(int xIn, int yIn, double r, double g, double b);

    // Getters
    point getCenter() const;
    double getArea() const;
    double getPerimeter() const;
    color getFill() const;

    // Setters
    void setPoint(point c);
    void setPoint(int xIn, int yIn);
    void move(int deltaX, int deltaY);
    void setColor(color f);
    void setColor(double r, double g, double b);
    // Note: no setters for area or perimeter
    // because those will be calculated in child classes
    // based on fields (radius, length and width, etc.)

    // pure virtual method is explicitly undefined
    virtual void draw() const = 0;
protected:
    point center;
    color fill;
    double area;
    double perimeter;

    // helper methods to calculate and set area and perimeter
    // pure virtual, defined in each subclass
    virtual void calculateArea() = 0;
    virtual void calculatePerimeter() = 0;
};

class Rect : public Shape {
private:
    double length;
    double width;
    void calculateArea() override;
    void calculatePerimeter() override;

public:
    // Constructors
    Rect();
    Rect(double l, double w);
    Rect(double l, double w, point c);
    Rect(double l, double w, int xIn, int yIn);
    explicit Rect(point c);
    Rect(int xIn, int yIn);
    explicit Rect(color f);
    Rect(double r, double g, double b);
    Rect(double l, double w, point c, color f);
    Rect(double l, double w, int xIn, int yIn, double r, double g, double b);
    // Note: area and perimeter are not input
    // but should be calculated when length and width are input

    // Getters
    double getLength() const;
    double getWidth() const;
    double getX() const;
    double getY() const;

    // Setter
    // Note: this method will also recalculate area and perimeter
    void setDimensions(double l, double w);

    void draw() const override;
};

#endif //FINALPROJECT120_SHAPES_H
