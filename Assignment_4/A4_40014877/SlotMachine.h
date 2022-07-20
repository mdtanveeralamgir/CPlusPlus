#ifndef A4_40014877_SLOTMACHINE_H
#define A4_40014877_SLOTMACHINE_H
#include <iostream>
#include <memory>
#include <array>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "Shape.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"
#include "SlotMachine.h"

using std::size_t;
using std::cout;
using std::endl;
using std::string;
using std::cin;
class SlotMachine {

private:
    std::size_t token {10}; //Initial token amount
    std::array<std::unique_ptr<Shape>, 3> reel{}; //Array of 3 random reels
    void makeShapes(); //Making shape
    void makeShape(int i); //Making and initializing random shapes and drawing 2D grid
    void displayBoxes(const Grid&, const Grid&, const Grid&) const; //Drawing 3 shapes side by side
    void printingBorder() const; //Printing top and bottom border
    void displayInstruction() const; //Displaying very first instruction
    int getToken() const; //cin, getting token amout from user
    bool findTwoSimilarShapes() const; //Returns true if 2 shapes are similar
    bool shapesEqualScrSize() const; //returns true if screen size of 2 shapes are similar
    bool threeSimilarShapes() const; //Returns true if 3 shapes are similar
    bool midScrIsGreater() const; //Returns true if middle shape's screen size is greater than left + right
    bool sameLeftRight() const; //Returns true if left and right shapes are same
    void jackpot(int); //Calculate and display message for jacpot
    void twoTimesBet(int); //Calculate and display message for 2X bet
    void oneTimeBet(int); //Calculate and display message for 1X bet
    void winsNothing(); //Display message when user wins nothing
    void loseBet(int); //Calculate and display message when lose bet
public:
    SlotMachine() = default; //Default constructor
    SlotMachine(size_t); //Constructor to assign value for initial token
    SlotMachine(const SlotMachine&) = delete; // deleted copy constructor
    SlotMachine& operator=(const SlotMachine&) = delete; // deleted assignment operator
    void run();
};

#endif //A4_40014877_SLOTMACHINE_H
