#ifndef A3_40014877_LINEMANAGER_H
#define A3_40014877_LINEMANAGER_H
#include "Menu.h"
#include "MiniDB.h"
#include <list>
#include <fstream>

class LineManager {
private:
    MiniDB<std::string> line_db {}; //An instance of MiniDB
    Menu fullMenu {}; //An instance of Full Menu
    Menu partialMenu {}; //An instance of Partial Menu
    std::size_t upperSpan {2}; //Upper span with default value of 2
    std::size_t lowerSpan {2};//Lower span with default value of 2
    bool isModified {false}; //true if line_db is modified but not written to the db and false otherwise.
    void setMenu(); //Set up both partial and full menu
    std::string getItemFromKeyBoard() const; //Read and return the string from user
    std::size_t displayMenu() const; //Print menu based on the size of the db and read option number from user
    std::string getFileName() const; //Read file name from user to either read from or write into
    int getInt() const; //Get and return int from user
    void clearCin() const; //Clean up cin before reading input from user
    bool fileExist(const std::string&); //CHeck if a file is exist. Used for of
    bool ifYes(); //Returns true if user wants to write to db before quiting
    std::ifstream openFileToRead() const; //Open a file and returns ifstream object
    void printWelcomeMsg(const std::string&);
public:
    LineManager() = default; //Default constructor
    virtual ~LineManager() = default; //Default destructor
    LineManager & operator=(const LineManager&) = delete; //Default assignment operator
    void run(); //runs the program (starting point)
    void appendItem(); //Append an item at the end of the list
    void insertItem(); //Insert an item at the current position
    void appendFromFile(); //Append items into list from a given file
    void insertFromFile();//Insert items into list from a given file
    void deleteCurrentLine(); //Delete line cp is currently pointing to
    void printCurrentLine() const; //Printing the line cp is currently pointing to
    void writeToDB(); //Writing the db into a file
    void printSpanOfLine(); //Printing span of lines from db
    void setUpperLowerSpan(); //Setting up upper / lower span
    void printAll(); // Print all the items in the list and sets cp to the end
    void moveCP(); //Move the cp to specif position as per user's request
    void writeToDBBeforeQuit(); //Before quiting user is asked if s/he wants to save db into a file
};



#endif //A3_40014877_LINEMANAGER_H
