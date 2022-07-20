#ifndef A4_40014877_RHOMBUS_H
#define A4_40014877_RHOMBUS_H
#include "Shape.h"

class Rhombus : public Shape {
private:
    size_t side {}; //Width of the Rhombus box
public:
    Rhombus(size_t, string name = "Diamond", string description = "Parallelogram with equal sides");
    virtual ~Rhombus() = default; //Virtual destructor
    virtual size_t getBoxHeight() const override; //Overriding box height
    virtual size_t getBoxWidth() const override; //Overriding box width
    virtual double geometricArea() const override; //Pure virtual method that returns shape's area
    virtual double geometricPerimeter() const override; //Pure virtual method that returns shape's perimeter
    virtual size_t screenArea() const override; //Pure virtual method that returns shape's screen area
    virtual size_t screenPerimeter() const override; //Pure virtual method that returns shape's screen perimeter
    virtual Grid draw(char fChar = '*', char bChar = ' ') const override; //Draw function override
};


#endif //A4_40014877_RHOMBUS_H
