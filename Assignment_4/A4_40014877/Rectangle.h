
#ifndef A4_40014877_RECTANGLE_H
#define A4_40014877_RECTANGLE_H
#include "Shape.h"
using std::size_t;
using std::ostream;
using std::vector;
class Rectangle: public Shape {
private:
    size_t width {}; //Width of the rect
    size_t height {}; //Height of the rect
public:
    Rectangle(size_t, size_t, string name = "Rectangle", string description = "Four right angles"); //Constructor
    virtual ~Rectangle() = default; //Virtual destructor
    virtual size_t getBoxHeight() const override; //Overriding box height
    virtual size_t getBoxWidth() const override; //Overriding box width
    virtual double geometricArea() const override; //Pure virtual method that returns shape's area
    virtual double geometricPerimeter() const override; //Pure virtual method that returns shape's perimeter
    virtual size_t screenArea() const override; //Pure virtual method that returns shape's screen area
    virtual size_t screenPerimeter() const override; //Pure virtual method that returns shape's screen perimeter
    virtual Grid draw(char fChar = '*', char bChar = ' ') const override; //Overriding the draw function

};


#endif //A4_40014877_RECTANGLE_H
