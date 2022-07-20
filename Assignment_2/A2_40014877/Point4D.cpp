/*
 * Submitted by:
 * Md Tanveer Alamgir
 * ID: 40014877
 */

#include "Point4D.h"
#include <array>
#include <cmath>

using std::endl;
using std::cout;
using std::abs;

//Default constructor
Point4D::Point4D (double x1, double x2, double x3, double x4) {
  this->point[0] = x1;
  this->point[1] = x2;
  this->point[2] = x3;
  this->point[3] = x4;
}

/*
 * ===========================================================================================================
 * Section 4.3
 * Subsection 4.3.1
 * Question no 1
 * Define the static members
 * ===========================================================================================================
 */

//Assigning value of tolerance
double Point4D::tolerance = 1.0E-6;

//Set tolerance
void Point4D::setTolerance (double tol) {
  tolerance = std::abs(tol);
}

//Get tolerance
double Point4D::getTolerance () {
  return tolerance;
}

/*
 * ===========================================================================================================
* End of Defining the static members
 * ===========================================================================================================
*/

/*
 * ===========================================================================================================
 * Section 4.3
 * Subsection 4.3.3
 * Question 6
 * Compound  Operators overload
 * ===========================================================================================================
*/

//Overloading += operator where RHS is a Point4D obj
Point4D &Point4D::operator+= (const Point4D &rhs) {
  //Using +(Point4D, Point4D) operator overloading
  *this = *this + rhs;
  return *this;
}

//Overloading += operator where RHS is a double
Point4D &Point4D::operator+= (double value) {
  //Using +(Point4D, double) operator overloading
  *this = *this + value;
  return *this;
}

//Overloading -= operator where RHS is a Point4D obj
Point4D &Point4D::operator-= (const Point4D &rhs) {
  //Using -(Point4D, Point4D) operator overloading
  *this = *this - rhs;
  return *this;
}

//Overloading -= operator where RHS is a double
Point4D &Point4D::operator-= (double value) {
  //Using -(Point4D, double) operator overloading
  *this = *this - value;
  return *this;
}

//Overloading *= operator where RHS is a Point4D obj
Point4D &Point4D::operator*= (const Point4D &rhs) {
  //Using *(Point4D, Point4D) operator overloading
  *this = *this * rhs;
  return *this;
}

//Overloading *= operator where RHS is a double
Point4D &Point4D::operator*= (double value) {
  //Using *(Point4D, double) operator overloading
  *this = *this * value;
  return *this;
}

//Overloading /= operator where RHS is a Point4D obj
Point4D &Point4D::operator/= (const Point4D &rhs) {
  //Using /(Point4D, Point4D) operator overloading
  *this = *this / rhs;
  return *this;
}

//Overloading *= operator where RHS is a double
Point4D &Point4D::operator/= (double value) {
  //Using /(Point4D, double) operator overloading
  *this = *this / value;
  return *this;
}

/*
 * ===========================================================================================================
* End of Compound Operators overload
 * ===========================================================================================================
*/

/*
 * ===========================================================================================================
 * Free Functions
 * Section 4.3
 * Subsection 4.3.3
 * Question 7
 * Basic arithmetic operation
 * ===========================================================================================================
 */

//Overloading + operator (Point4D, Point4D)
Point4D operator+ (const Point4D &lhs, const Point4D &rhs) {
  Point4D temp;
  for (size_t i{1}; i <= temp.getPointSize(); i++) {
    temp[i] = lhs[i] + rhs[i];
  }
  return temp;
}

//Overloading + operator (double, Point4D)
Point4D operator+ (double lhs, const Point4D &rhs) {
  //Using +(Point4D , double) method to add.
  return rhs + lhs;
}

//Overloading + operator (Point4D, double)
Point4D operator+ (const Point4D &lhs, double rhs) {
  Point4D temp;
  for (size_t i{1}; i <= lhs.getPointSize(); i++) {
    temp[i] = lhs[i] + rhs;
  }
  return temp;
}

//Overloading * operator (Point4D, Point4D)
Point4D operator* (const Point4D &lhs, const Point4D &rhs) {
  Point4D temp;
  temp[1] = (lhs[1] * rhs[1]) + (lhs[2] * rhs[4]);
  temp[2] = (lhs[1] * rhs[2]) + (lhs[2] * rhs[3]);
  temp[3] = (lhs[4] * rhs[2]) + (lhs[3] * rhs[3]);
  temp[4] = (lhs[4] * rhs[1]) + (lhs[3] * rhs[4]);
  cout << temp[4];
  return temp;
}

//Overloading * operator (double, Point4D)
Point4D operator* (double lhs, const Point4D &rhs) {
  Point4D temp;
  for (size_t i{1}; i <= temp.getPointSize(); i++) {
    temp[i] = lhs * rhs[i];
  }
  return temp;
}

//Overloading * operator (Point4D, double)
Point4D operator* (const Point4D &point, double value) {
  //Using +(double, Point4D) overloaded operator
  return value * point;
}

//Overloading - operator (Point4D, Point4D)
Point4D operator- (const Point4D &lhs, const Point4D &rhs) {
  Point4D temp;
  for (size_t i{1}; i <= temp.getPointSize(); i++) {
    temp[i] = lhs[i] - rhs[i];
  }
  return temp;
}

//Overloading - operator (double, Point4D)
Point4D operator- (double lhs, const Point4D &rhs) {
  Point4D temp;
  for (size_t i{1}; i <= temp.getPointSize(); ++i) {
    temp[i] = lhs - rhs[i];
  }
  return temp;
}

//Overloading - operator (double, Point4D)
Point4D operator- (const Point4D &lhs, double rhs) {
//Using -obj and (double - Point4D) methods to achieve below return.
  return -(rhs - lhs);
}

//Overloading / operator (Point4D, Point4D)
Point4D operator/ (const Point4D &lhs, const Point4D &rhs) {
  cout << " lhs " << lhs << endl;
  cout << " rhs " << rhs << endl;
  return lhs * (rhs.inverse());
}

//Overloading / operator (double, Point4D)
Point4D operator/ (double value, const Point4D &point) {
  return value * (point.inverse());
}

//Overloading / operator (Point4D, double)
Point4D operator/ (const Point4D &point, double value) {

//  if (value != 0) {
////    value = 1 / value;
//  value = abs(value);
//  } else {
//    throw std::overflow_error("The value can't be 0");
//  }
if(abs(value) < Point4D::getTolerance()){
  throw std::overflow_error("The value can't be 0");
} else {
  //value = 1/value;
  return Point4D(point[1] / value, point[2] / value, point[3] /value, point[4] / value);
}

}

/*
 * ===========================================================================================================
 * End of Basic arithmetic operators overloading
 * ===========================================================================================================
*/

/*
 * ===========================================================================================================
 * Free Functions
 * Section 4.3
 * Subsection 4.3.3
 * Question 8
 * Relational operator overloading
 * ===========================================================================================================
*/

//Overloading == operator
bool operator== (const Point4D &lhs, const Point4D &rhs) {
//Using -operator(Point4D, Point4D) and Point4D() to get abs(Point4d - Point4D)
  return (lhs - rhs)() <= Point4D::getTolerance();
}

//Overloading != operator
bool operator!= (const Point4D &lhs, const Point4D &rhs) {
  //Using ==operator(Point4D, Point4D) overloading
  return !(lhs == rhs);
}

//Overloading < operator
bool operator< (const Point4D &lhs, const Point4D &rhs) {
//Using != ; () ; and < operator overloading
  return (lhs != rhs) && (lhs() < rhs());
}

//Overloading > operator
bool operator> (const Point4D &lhs, const Point4D &rhs) {
  //Using <operator(Point4D, Point4D) overloading and swapping lhs, rhs.
  return rhs < lhs;
}

//Overloading <= operator
bool operator<= (const Point4D &lhs, const Point4D &rhs) {
  //Using < and == operator overloading
  return (lhs < rhs) || (lhs == rhs);
}

//Overloading >= operator
bool operator>= (const Point4D &lhs, const Point4D &rhs) {
  //Using < operator overloading
  return !(lhs < rhs);
}

/*
 * ===========================================================================================================
 * End of relational operators overloading
 * ===========================================================================================================
 */

/*
 * ===========================================================================================================
 * Section 4.3
 * Subsection 4.3.3
 * Question 9
 * Unary operator Operators overload
 * ===========================================================================================================
*/

//Overloading +obj operator
Point4D Point4D::operator+ () {
  return *this;
}

//Overloading -obj operator
Point4D Point4D::operator- () {
  //Using * (double, Point4D) overload method to overload this method
  Point4D temp;
  temp = -1 * *this;
  return temp;
}

//Overloading prefix operator ++obj
Point4D &Point4D::operator++ () {
  *this = *this + 1.0;
  return *this;
}

//Overloading prefix operator --obj
Point4D &Point4D::operator-- () {
  *this = *this - 1.0;
  return *this;
}

//Overloading postfix operator obj++
Point4D Point4D::operator++ (int) {
  Point4D temp{*this};
  //Using prefix overloaded operator to increment the value of this
  ++(*this);
  return temp;
}

//Overloading postfix operator obj--
Point4D Point4D::operator-- (int) {
  Point4D temp{*this};
  //Using prefix overloaded operator to decrement the value of this
  --(*this);
  return temp;
}

/*
 * ===========================================================================================================
 * End of Unary operator Operators overload
 * ===========================================================================================================
*/

/*
 * ===========================================================================================================
 * Section 4.3
 * Subsection 4.3.3
 * Question 10
 * Subscript [] operator overloading (Both const and non-const)
 * ===========================================================================================================
*/

//[] overload. returning reference to be able to modify the value of point[int]
double &Point4D::operator[] (int index) {
  --index;
  if (index < 0 || index > this->point.size() - 1) {
    throw std::out_of_range("index out of bounds");
  } else {
    return this->point.at(index);
  }
}

//[] overload. Returning the value of point[int]. Return type is constant and the method itself is constant
const double Point4D::operator[] (int index) const {
  --index;
  if (index < 0 || index > this->point.size() - 1) {
    throw std::out_of_range("index out of bounds");
  } else {
    return this->point.at(index);
  }
}

/*
 * ===========================================================================================================
 * End of subscript Operator overloading
 * ===========================================================================================================
*/

/*
 * ===========================================================================================================
 * Section 4.3
 * Subsection 4.3.3
 * Question 11 and 14
 * Function call operator () overloading and
 * Implementing absoluteValue() member function
 * ===========================================================================================================
*/

//Overloading operator() to return the sum of abs value of point
double Point4D::operator() () const {
  double result{0};
  for (size_t i = 1; i <= this->getPointSize(); ++i) {
    result += abs(this->operator[](i));
  }
  return result;
}

//Return the absolute value of a Point4D obj
double Point4D::absoluteValue () {
  //Calling operator()
  return this->operator()();
}

/*
 * ===========================================================================================================
 * End of function call Operator () overloading and implementation of absoluteValue()
 * ===========================================================================================================
*/

/*
 * ===========================================================================================================
 * Section 4.3
 * Subsection 4.3.3
 * Question 12 and 13
 * Overloading extraction >> operator
 * Overloading insertion << operator
 * ===========================================================================================================
*/

//Overloading >> operator
std::istream &operator>> (std::istream &in, Point4D &point4D) {
  in >> point4D.point[0];
  in >> point4D.point[1];
  in >> point4D.point[2];
  in >> point4D.point[3];
  return in;
}

//Overloading << operator
std::ostream &operator<< (std::ostream &out, const Point4D &point4D) {
  out << "[ ";
  out << point4D.point[0] << ", ";
  out << point4D.point[1] << ", ";
  out << point4D.point[2] << ", ";
  out << point4D.point[3] << " ]";
  out << endl;
  return out;
}

/*
 * ===========================================================================================================
 * End of Extraction  >> and insertion << operator
 * ===========================================================================================================
*/

//Inverse and return the value of an obj
Point4D Point4D::inverse () const {
  double beta = (this->point[0] * this->point[2]) - (this->point[1] * this->point[3]);
  if (abs(beta) < tolerance) {
    throw std::overflow_error("Encountered division by zero while inverting a Point4D");
  }
  return Point4D(this->point[2] / beta, -this->point[1] / beta, this->point[0] / beta, -this->point[3] / beta);

}

//Get size of point[]
size_t Point4D::getPointSize () const {
  return this->point.size();
}













