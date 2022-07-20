#include "AcuteTriangle.h"
#include <cmath>
AcuteTriangle::AcuteTriangle(size_t ATWidth, string name, string description)
:Triangle(ATWidth, ATWidth, name, description)
{}

//Returns height
size_t AcuteTriangle::getBoxWidth() const {
  size_t width = Triangle::getBoxWidth();
  width = width % 2 == 0 ? width + 1 : width;
  return width;
}

//Returns height
size_t AcuteTriangle::getBoxHeight() const {
  size_t height = this->getBoxWidth();
  height = (height + 1) / 2;
  return height;
}

//Calculate and returns the geometric perimeter
double AcuteTriangle::geometricPerimeter() const {
  double result {pow(this->getBoxWidth(), 2)}; //width^2
  result += 4 * (pow(this->getBoxHeight(), 2)); //(4 * height^2)
  result = sqrt(result);
  result += this->getBoxWidth();
  return result; //Geometric perimeter = (2+ sqrt2)height
}

//Calculate and returns the screen area
size_t AcuteTriangle::screenArea() const {
  return pow(this->getBoxHeight(), 2); // Screen area = height^2
}

//Calculate and returns the screen perimeter
size_t AcuteTriangle::screenPerimeter() const {
  size_t result {this->getBoxHeight() - 1};
  result *= 4;
  return result; //Screen perimeter = 3(h−1)
}

Grid AcuteTriangle::draw(char fChar, char bChar) const {
  vector<char> rowv;
  vector<vector<char>> colv;
  int space = (this->getBoxWidth() - 1)/2;
  int printStar {1};
  int row {0};
  int col {int(this->getBoxWidth() -  1)};
  col /= 2;
  col += 1;

  for (int i = 0; i < col; i++) //Iteration column
  {
    while(row < space){ //Inserting background before the foreground
      rowv.push_back(bChar);
      row++;
    }
    row = 0;

    while(row < printStar){ //Inserting foreground
      rowv.push_back(fChar);
      row++;
    }
    row = 0;

    while(row < space){ //Inserting background after inserting foreground
      rowv.push_back(bChar);
      row++;
    }
    row = 0;

    colv.push_back(rowv); //Inserting row into column, 2D vector
    rowv.clear(); //Emptying row
    space--; //Decrementing background
    printStar += 2; //Increasing foreground by 2

  }
  return colv;
}