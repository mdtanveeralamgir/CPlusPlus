#ifndef A4_40014877_RIGHTTRIANGLE_H
#define A4_40014877_RIGHTTRIANGLE_H
#include "Triangle.h"

class RightTriangle : public Triangle {

public:
    RightTriangle(size_t, string = "Ladder", string = "One right and two acute angles"); //Constructor
    virtual ~RightTriangle() = default; //Virtual destructor
    virtual double geometricPerimeter() const override; //Pure virtual method that returns shape's perimeter
    virtual size_t screenArea() const override; //Pure virtual method that returns shape's screen area
    virtual size_t screenPerimeter() const override; //Pure virtual method that returns shape's screen perimeter
    virtual Grid draw(char fChar = '*', char bChar = ' ') const override; //Overriding draw function
};


#endif //A4_40014877_RIGHTTRIANGLE_H
