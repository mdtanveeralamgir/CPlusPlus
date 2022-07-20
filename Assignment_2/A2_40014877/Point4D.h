/*
 * Submitted by:
 * Md Tanveer Alamgir
 * ID: 40014877
 */

#ifndef A2_40014877_POINT4D_H
#define A2_40014877_POINT4D_H

#include <array>
#include <iostream>

class Point4D {
private:
    //Declaring array of double with 4 elements
    std::array<double, 4> point;
    //Declaring tolerance
    static double tolerance;

public:
    //Inverse
    Point4D inverse () const;

   /*
     *===========================================================================================================
     * Getter and setter
     *===========================================================================================================
     */

    //Set the tolerance
    static void setTolerance (double tol);

    //Getter for tolerance
    static double getTolerance ();

    //Get the size of the point array
    size_t getPointSize () const;

    /*
    *===========================================================================================================
    * End of Getter and setter
    *===========================================================================================================
    */

    /*
     *===========================================================================================================
     * Section 4.3
     * Subsection 4.3.2
     * Question 2, 3, 4, 5
     * explicit Constructor with default value of 0 for each argument
     * Default copy construction
     * Default assignment operator
     * Default destructor
     *===========================================================================================================
     */

    //Default constructor
    explicit Point4D (double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0);

    //Default copy constructor
    Point4D (const Point4D &) = default;

    //Default assignment operator
    Point4D &operator= (const Point4D &) = default;

    //Default destructor
    virtual ~Point4D () = default;

    /*
     * ===========================================================================================================
     * End of subsection 4.3.2
     * ===========================================================================================================
     */

    /*
     * ===========================================================================================================
     * Compound assignment Operators overload
     * ===========================================================================================================
     */
    //Overloading += operator
    Point4D &operator+= (const Point4D &);

    Point4D &operator+= (double);

    //Overloading -= operator
    Point4D &operator-= (const Point4D &);

    Point4D &operator-= (double);

    //Overloading *= operator
    Point4D &operator*= (const Point4D &);

    Point4D &operator*= (double);

    //Overloading /= operator
    Point4D &operator/= (const Point4D &);

    Point4D &operator/= (double);

    /*
     * ===========================================================================================================
     * End of Compound assignment Operators overload
     * ===========================================================================================================
     */

    /*
    * ===========================================================================================================
    * Function call () operator overload and absoluteValue() method declaration
    * ===========================================================================================================
    */

    //Overloading () operator
    double operator() () const;

    //absoluteValue to return the absolute value of invoking obj
    double absoluteValue ();

    /*
     * ===========================================================================================================
     * Function call () operator overload and absoluteValue() method declaration
     * ===========================================================================================================
     */

    /*
     * ===========================================================================================================
     * Unary Operators overload
     * ===========================================================================================================
     */

    //Overloading +obj operator
    Point4D operator+ ();

    //Overloading -obj operator
    Point4D operator- ();

    //Overloading ++obj operator
    Point4D &operator++ ();

    //Overloading --obj operator
    Point4D &operator-- ();

    //Overloading obj++ operator
    Point4D operator++ (int);

    //Overloading obj-- operator
    Point4D operator-- (int);

    /*
     * ===========================================================================================================
     * End of Unary Operators overload
     * ===========================================================================================================
    */

    /*
     * ===========================================================================================================
     * Subscript Operator overloading
     * ===========================================================================================================
     */

    //[] overload. returning reference to be able to modify the value of point[int]
    double &operator[] (int);

    //[] overload. Returning the value of point[int]. Return type is constant and the method itself is constant
    const double operator[] (int) const;

    /*
    * ===========================================================================================================
    * End of subscript Operators overloading
    * ===========================================================================================================
   */

    /*
     * ===========================================================================================================
     * Extraction >> and Insertion << Operators overloading
     * ===========================================================================================================
     */

    //Overloading >> operator
    friend std::istream &operator>> (std::istream &, Point4D &);

    //Overloading << operator
    friend std::ostream &operator<< (std::ostream &, const Point4D &);

    /*
    * ===========================================================================================================
    * End of Extraction >> and Insertion << Operators overloading
    * ===========================================================================================================
    */

};
//FREE FUNCTIONS

/*
 * ===========================================================================================================
 * Relational operator overloading
 * ===========================================================================================================
 */

//Overloading == operator
bool operator== (const Point4D &, const Point4D &);

//Overloading != operator
bool operator!= (const Point4D &, const Point4D &);

//Overloading < operator
bool operator< (const Point4D &, const Point4D &);

//Overloading <= operator
bool operator<= (const Point4D &, const Point4D &);

//Overloading > operator
bool operator> (const Point4D &, const Point4D &);

//Overloading >= operator
bool operator>= (const Point4D &, const Point4D &);

/*
 * ===========================================================================================================
 *End of Relational operator overloading
 * ===========================================================================================================
 */

/*
 * ===========================================================================================================
 * Basic arithmetic operators overloading
 * ===========================================================================================================
 */

//Overloading + operator
Point4D operator+ (const Point4D &, const Point4D &);

Point4D operator+ (const Point4D &, double);

Point4D operator+ (double, const Point4D &);

//Overloading * operator
Point4D operator* (const Point4D &, const Point4D &);

Point4D operator* (const Point4D &, double);

Point4D operator* (double, const Point4D &);

//Overloading - operator
Point4D operator- (const Point4D &, const Point4D &);

Point4D operator- (const Point4D &, double);

Point4D operator- (double, const Point4D &);

//Overloading / operator
Point4D operator/ (const Point4D &, const Point4D &);

Point4D operator/ (const Point4D &, const double);

Point4D operator/ (double, const Point4D &);

/*
 * ===========================================================================================================
 * End of Basic arithmetic operators
 * ===========================================================================================================
 */

#endif
