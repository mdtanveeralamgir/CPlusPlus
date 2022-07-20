#include "RightTriangle.h"
#include <cmath>
RightTriangle::RightTriangle(size_t rtHeight, string name, string description)
:Triangle(rtHeight, rtHeight, name, description)
{}

//Calculate and returns the geometric perimeter
double RightTriangle::geometricPerimeter() const {
  double result {2};
  result += sqrt(2);
  result *= Triangle::getBoxHeight();
  return result; //Geometric perimeter = (2+ sqrt2)height
}

//Calculate and returns the screen area
size_t RightTriangle::screenArea() const {
  size_t result {this->Triangle::getBoxHeight() + 1};
  result *= this->Triangle::getBoxHeight();
  result /= 2;

  return result; // Screen area = 2n(n+1)+1, n = ⌊height/2⌋
}

//Calculate and returns the screen perimeter
size_t RightTriangle::screenPerimeter() const {
  size_t result {this->Triangle::getBoxHeight() - 1};
  result *= 3;
  return result; //Screen perimeter = 3(h−1)
}

Grid RightTriangle::draw(char fChar, char bChar) const {
  vector<char> rowv; //Row
  vector<vector<char>> colv; //2D col

  int printStar {1}; //Initial start foreground to print
  int col {int(this->getBoxWidth())}; //Getting the width

  for (int i = 0; i < col; i++)
  {
    int row {0};
    //inserting foreground char into the row
    while(row < printStar){
      rowv.push_back(fChar); //Inserting foreground
      row++;
    }

    //Inserting background into the row
    while(row < this->getBoxWidth()){
      rowv.push_back(bChar); //inserting background
      row++;
    }

    colv.push_back(rowv); //Inserting the row into 2D vector
    rowv.clear(); //Emptying row
    printStar++; //Increasing the number of foreground to be inserted

  }
  return colv;
}