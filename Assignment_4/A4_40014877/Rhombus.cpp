#include "Rhombus.h"
#include <cmath>
Rhombus::Rhombus(size_t widthAndHeight, string name, string description)
: Shape(name, description)
{
  side = (widthAndHeight % 2) == 0 ? widthAndHeight + 1 : widthAndHeight;

}

//Returns height
size_t Rhombus::getBoxHeight() const {
  return this->side;
}

//Returns width
size_t Rhombus::getBoxWidth() const {
  return this->side;
}

//Calculate and returns the geometric area
double Rhombus::geometricArea() const {
  double result {};
  result = pow(this->side, 2);
  result /= 2;
  return result; // Geometric area = (height * height)/2
}

//Calculate and returns the geometric perimeter
double Rhombus::geometricPerimeter() const {
  double result {2};
  result *= sqrt(2);
  result *= this->side;
  return result; //Geometric perimeter = (2(sqrt(height)))height
}

//Calculate and returns the screen area
size_t Rhombus::screenArea() const {
  size_t result {};
  int n = floor(this->side / 2);
  result = 2 * n;
  result *= (n + 1);
  result += 1;
  return size_t (result); // Screen area = 2n(n+1)+1, n = ⌊height/2⌋
}

//Calculate and returns the screen perimeter
size_t Rhombus::screenPerimeter() const {
  return size_t ( 2 *  (this->side - 1)); //Screen perimeter = 2(height−1)
}

Grid Rhombus::draw(char fChar, char bChar) const {
  vector<char> rowv; //Row
  vector<vector<char>> colv; //Column
  int space = (this->side - 1)/2; //Initial space based on the side
  int printStar {1}; //Initial start to print
  int row {0};
  int col {int(this->side -  1)}; //Initializing column based on the side
  col /= 2;
  col += 1;

  for (int i = 0; i < col; i++) //Iterating through column
  {
    while(row < space){
      rowv.push_back(bChar); //Inserting background in each row before inserting foreground
      row++;
    }
  row = 0; //Making row 0 again for foreGround to be inserted
  // Print i+1 stars
  while(row < printStar){
    rowv.push_back(fChar); //Inserting foreground in each row
    row++;
  }
  row = 0;

  while(row < space){
    rowv.push_back(bChar); //Inserting background in each row after inserting foreground
    row++;
  }
  row = 0;

  colv.push_back(rowv); //Inserting rows at the back of the 2D vector
  rowv.clear(); //Emptying the row
  space--; //In each iteration background will decrease
  printStar += 2; //In each iteration foreground will decrease

}
  //Until this point we have a Acute triangle. Now insert in reverse order to make it a Rhombus, except base
  for(int dReverse {int(colv.size() - 2)}; dReverse >= 0; dReverse--){
    colv.push_back(colv.at(dReverse));
  }
  return colv;
}