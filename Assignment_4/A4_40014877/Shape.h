#ifndef A4_40014877_SHAPE_H
#define A4_40014877_SHAPE_H
#include <string>
#include <iostream>
#include <vector>
using std::size_t;
using std::string;
using std::ostream;
using std::vector;
using Grid = vector<vector<char>>; // a vector of vectors of chars

class Shape {
    friend ostream& operator<<(ostream&, const Shape&); //ostream overload to print the info of shapes

private:
    static size_t identityNumber; //Get us a unique identifier for each shape generated
    string shapeName {}; //Name of the shape
    string shapeDescription {}; //Description of the shape
public:
    Shape(string, string); //Constructor to set name and description
    virtual ~Shape() = default; //Default destructor
    static size_t getIdentityNumber(); //Getter to get the identifier
    string getShapeName() const; //Returns shape's name
    string getShapeDescription() const; //Returns Shape's description
    virtual size_t getBoxHeight() const = 0;
    virtual size_t getBoxWidth() const = 0;
    void setShapeName(string); //Sets up shape's name
    void setShapeDescription(string); //Sets up shape's description
    string toString() const; //String representation of shape
    virtual double geometricArea() const = 0; //Pure virtual method that returns shape's area
    virtual double geometricPerimeter() const = 0; //Pure virtual method that returns shape's perimeter
    virtual size_t screenArea() const = 0; //Pure virtual method that returns shape's screen area
    virtual size_t screenPerimeter() const = 0; //Pure virtual method that returns shape's screen perimeter
    virtual Grid draw(char fChar = '*', char bChar = ' ') const = 0;
};

ostream & operator<<(ostream & out, const Grid & grid); //istream operator overload to print a single shape


#endif //A4_40014877_SHAPE_H
