#ifndef A4_40014877_ACUTETRIANGLE_H
#define A4_40014877_ACUTETRIANGLE_H
#include "Triangle.h"

class AcuteTriangle : public Triangle {

public:
    AcuteTriangle(size_t,  string = "Wedge", string = "Three acute angles");
    virtual ~AcuteTriangle() = default; //Virtual destructor
    virtual size_t getBoxWidth() const override; //Overriding box width
    virtual size_t getBoxHeight() const override; //Overriding box height
    virtual double geometricPerimeter() const override; //Pure virtual method that returns shape's perimeter
    virtual size_t screenArea() const override; //Pure virtual method that returns shape's screen area
    virtual size_t screenPerimeter() const override; //Pure virtual method that returns shape's screen perimeter
    virtual Grid draw(char fChar = '*', char bChar = ' ') const override; //Overriding draw member function
};


#endif //A4_40014877_ACUTETRIANGLE_H
