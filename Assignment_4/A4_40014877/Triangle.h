#ifndef A4_40014877_TRIANGLE_H
#define A4_40014877_TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape {
private:
  size_t width{}; //Width of the triangle
  size_t height{}; //Height of the triangle
public:
    Triangle(size_t, size_t, string, string); //Constructor
    virtual ~Triangle() = default; //Virtual destructor
    size_t getBoxWidth() const override; //Override Box width
    size_t getBoxHeight() const override; //Override bos height member function
    double geometricArea() const override; //Pure virtual method that returns shape's area

};


#endif //A4_40014877_TRIANGLE_H
