.............................. Introduction .......................


COMP 5421
Advanced Programming
Assignment 3
Submitted By:
MD Tanveer Alamgir
ID: 40014877

C++ version: 14
Compiler: gcc
IDE: Clion
Program ran and tested on MAC OS.

........................... Fulfillment ...........................

All the requirements have been implemented successfully.
Achieved the test result provided in the question.

	

......................... Small Modification ......................

-> Top and Bottom Message 

std::string topMessage {"Choose one of the following options:"}; 
  
std::string bottomMessage {"Enter an option number"};

Top and bottom message holds default value


-> Append and Insert via getline

void LineManager::appendItem()
void LineManager::insertItem()

If user exits (entering dot ".") from above functions without appending / inserting any value into the db then current position will not reset. This is obvious but was not mentioned in the requirement.

This 2 functions also allow to insert empty string. I commented out the lines of code that will not append / insert empty string (Line 91 and 113 in LineManager.cpp).


-> Append and Insert from a file

In below member functions:

void LineManager::appendFromFile()
void LineManager::insertFromFile()

If there is an empty line in the file, that empty line will not get added in the db.



