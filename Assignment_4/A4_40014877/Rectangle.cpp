
#include "Rectangle.h"

Rectangle::Rectangle(size_t recWidth, size_t recHeight, string name, string description)
: width{recWidth}, height{recHeight}, Shape(name, description)
{}

//Returns height
size_t Rectangle::getBoxHeight() const {
  return this->height;
}

//Returns width
size_t Rectangle::getBoxWidth() const {
  return this->width;
}

//Calculate and returns the geometric area
double Rectangle::geometricArea() const {
  return double(this->getBoxHeight() * this->getBoxWidth()); // Geometric area = height * width
}

//Calculate and returns the geometric perimeter
double Rectangle::geometricPerimeter() const {
  return double(2 * (this->getBoxHeight() + this->getBoxWidth())); //Geometric perimeter = 2(height + width)
}

//Calculate and returns the screen area
size_t Rectangle::screenArea() const {
  return size_t (this->geometricArea()); // Screen area = height * width
}

//Calculate and returns the screen perimeter
size_t Rectangle::screenPerimeter() const {
  return size_t (this->geometricPerimeter() - 4); //Screen perimeter = geometric perimeter - 4
}

//Drawing the rectangle
Grid Rectangle::draw(char fChar, char bChar) const {
  vector<char> rowv; //Row
  vector<vector<char>> colv; //Col, 2D vector
  for(size_t col {0}; col < this->getBoxHeight(); col++){ //Iterating through col
    for(size_t row {0}; row < this->getBoxWidth(); row++){ //Iterating through row
      rowv.push_back(fChar); //Inserting the foreground in the row
    }
    colv.push_back(rowv); //Inserting the row in the col 2D vector
    rowv.clear(); //Erasing elements in the row
  }
  return colv;
}
