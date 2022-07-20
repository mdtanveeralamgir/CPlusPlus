#include "Shape.h"
#include <iomanip>
#include <typeinfo>
#include <sstream>
using std::setfill;
using std::setw;
using std::internal;
using std::ostream;

//Constructor taking parameters to set up name, description, height and width
Shape::Shape(string name, string description)
:shapeName{name}, shapeDescription {description}
{
  identityNumber++; //Increasing the static unique identifier for each shape creates
}


//Initializing identifier
size_t Shape::identityNumber = 0;

//Returns current identifier
size_t Shape::getIdentityNumber() {
  return identityNumber;
}

//Returns name of the shape
string Shape::getShapeName() const {
  return this->shapeName;
}

//Returns name of the shape
string Shape::getShapeDescription() const {
  return this->shapeDescription;
}



//Set up the name of the shape
void Shape::setShapeName(string name) {
  this->shapeName = name;
}

//Set up new value for description
void Shape::setShapeDescription(string description) {
  this->shapeDescription = description;
}

//Returns the info of shape in string form
 string Shape::toString() const{
   std::stringstream sStream{};
   sStream << "Shape information\n" << "-----------------\n" << setfill(' ')  << internal
  << "id:" << setw(13) << this->getIdentityNumber()
  << "\nShape name:" << setw(13) << this->getShapeName()
  << "\nDescription:" << setw(20) << this->getShapeDescription()
  << "\nB. box width:" << setw(3) << this->getBoxWidth()
  << "\nB. box height:" << setw(2) << this->getBoxHeight()
  << "\nScr area:" << setw(8) << this->screenArea()
  << "\nGeo area:" << setw(11) << std::fixed << std::setprecision(2) << this->geometricArea()
  << "\nScr perimeter:" << setw(3) << this->screenPerimeter()
  << "\nGeo perimeter:" << setw(6) << std::fixed << std::setprecision(2) << this->geometricPerimeter()
  << "\nStatic type:" << setw(10) << typeid(this).name()
  << "\nDynamic type:" << setw(12) << typeid(*this).name();
  return sStream.str();
}

//ostream operator overload to print info of shapes
std::ostream& operator<<(std::ostream &out, const Shape &b)
{
  out << b.toString();
  return out;
}

//Printing grid
ostream & operator<<(ostream & out, const Grid & grid){
  for(std::size_t n {0}; n < grid.size(); n++){ //Iterating through each column
    for (std::size_t i = 0; i < grid[n].size(); i++) { //Iterating through each row
      out << grid[n][i]; //Printing each element in the 2D vector
    }
    out << std::endl;
  }
  return out;
}