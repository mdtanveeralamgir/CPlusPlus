
#include "Triangle.h"

Triangle::Triangle(size_t triWidth, size_t triHeight, string name, string description)
: width{triWidth}, height{triHeight}, Shape(name, description)
{}

//Returns width
size_t Triangle::getBoxWidth() const {
  return this->width;
}

//Returns height
size_t Triangle::getBoxHeight() const {
  return this->height;
}

//Calculate and returns the geometric area
double Triangle::geometricArea() const {
  double result {double(this->getBoxHeight() * this->getBoxWidth())};
  return result / 2; // Geometric area = height * width
}