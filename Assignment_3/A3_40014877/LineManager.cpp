#include "LineManager.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using std::cin;
using std::string;
using std::cout;
using std::endl;


/*
 * Starting point of the program (init)
 * Fist set up menu (Partial / Full depending on the size of the line_db)
 * Keep displaying menu until user quit
 * Keep reading option from user
 * Catch logic_error(s)
 */
void LineManager::run() {
  this->printWelcomeMsg("Welcome to LineManager!"); //Printing welcome message
  this->setMenu(); //Set up menu
  std::size_t option {}; //To store option selected by user
  bool quit {false}; //If user select 5 for partial menu and 12 for full menu

  while (!quit) { //Check if user wants to quit when db is empty
    option = this->displayMenu(); //Display the partial / full menu based on the size of the db and read the option number from user
    quit = (option == 5 && !line_db.size()); // Check if the line_db is empty and user wants to quit
    if(quit) //Check the intention of user
      break; //If user wants to quit it breaks the while loop. This is important despite while loop condition so when user enters option 5 it does not execute printCurrentLine() function.
    try {
      switch (option) {
        case 1: // User selected to append
            this->appendItem();
          break;
        case 2: //User selected to insert
            this->insertItem();
          break;
        case 3: //User selected to append from file
          this->appendFromFile();
          break;
        case 4: //User selected to insert from file
          this->insertFromFile();
          break;
        case 5: //User selected to print the current line
          this->printCurrentLine();
          break;
        case 6: //User selected to print span of lines
          this->printSpanOfLine();
          break;
        case 7: //User selected to set up upper / lower span
          this->setUpperLowerSpan();
          break;
        case 8: //User wants to print the whole DB
          this->printAll();
          break;
        case 9: //User wants to move the current position to specific index
          this->moveCP();
          break;
        case 10: //User wants to remove the current line
          this->deleteCurrentLine();
          break;
        case 11: //User wants to write DB to file
          this->writeToDB();
          break;
        case 12: //User wants to quit when DB is not empty
         this->writeToDBBeforeQuit(); //User gets the chance to write the db into file before quit
         quit = true; //quit becomes true to break the while loop
          break;
      }
    }
    //Catching logic_errors
    catch(std::logic_error logicError){
      std::cerr << logicError.what() << endl; //Printing error message
    }
  }
  cout << "Good bye" << endl;
}

/*
 * Append into line_db
 */

void LineManager::appendItem(){
  cout << "To end input, enter a single dot and press enter" << endl; // Message
  std::size_t lineNumber {1}; //Line number while appending an item: 1->
  std::size_t initialListSize {line_db.size()}; //Size of db before appending an element
  this->clearCin(); // Clean up the cin before getting the input
  cout << lineNumber++ << "-> "; //Printing line number and then post increment
  std::string input{this->getItemFromKeyBoard()}; //Initializing input string and calling getItemFromKeyBoard for user to insert item
  while (input != "."){ //Keep looping until user insert a single dot (.)
    cout << lineNumber++ << "-> ";
    //if(!input.empty())
      line_db.append(input); //Appending using append member function from line_db
    input = this->getItemFromKeyBoard(); //Getting the input again
  }
  if(line_db.size() > initialListSize){ //Making sure an item has been inserted by comparing size before appended and after appended.
    this->isModified = true; //setting the value of flag isModified true to indicate the db has been modified
  }
}

/*
 * Inserting into db
 */

void LineManager::insertItem() {
  cout << "To end input, enter a single dot and press enter" << endl; // Message
  std::size_t initialListSize {line_db.size()}; //Size of bd before inserting an element
  std::size_t lineNumber {1}; //Line number while appending an item: 1->
  this->clearCin(); // Clean up the cin before getting the input
  cout << lineNumber++ << "-> "; //Printing line number and then post increment
  std::string input{this->getItemFromKeyBoard()}; //Initializing input string and calling getItemFromKeyBoard for user to insert item
  while (input != "."){ //Keep looping until user insert a single dot (.)
    cout << lineNumber++ << "-> ";
    //if(!input.empty())
      line_db.insert(input); //Inserting into db
    input = this->getItemFromKeyBoard(); //Getting the input from user again
  }
  if(line_db.size() > initialListSize){ //Making sure an item has been inserted by comparing size before appended and after appended.
    line_db.prev(); //Move the cp one item backward
    this->isModified = true; //setting the value of flag isModified true to indicate the db has been modified
  }
}



/*
 * Append text from file
 * I made a small modification so the empty line wont be added into the db
 */

void LineManager::appendFromFile() {
  std::ifstream fromFile {this->openFileToRead()};
  std::string line {}; //string to store line
  if(!fromFile){ //If the file is not access able
    std::cerr << "Can't access the file!" << endl;
  }
  else{
    while(!fromFile.eof()){
      std::getline(fromFile, line); //Getting the line
      if(!line.empty()) { //If the line is not empty
        line_db.append(line); //Append line into DB
      }
    }
    this->isModified = true; //Since the db has been modified so isModified becomes true
  }
  fromFile.close(); //Closing the file
}


/*
 * Insert text from file
 * I made a small modification so the empty line wont be added into the db
 */

void LineManager::insertFromFile() {
  std::ifstream fromFile {this->openFileToRead()};
  std::string line {}; //string to store line
  if(!fromFile){ //If the file is not access able
    std::cerr << "Can't access the file!" << endl;
  }
  else{
    while(!fromFile.eof()){ //Loop through until the end of the line of the file
      std::getline(fromFile, line); //Getting the line
      if(!line.empty()) { //If the line is not empty
        line_db.insert(line); //Append line into DB
      }
    }
    line_db.prev(); //After inserting the lines from file cp moves one step back to point to last entered element
    this->isModified = true; //Since the db has been modified so isModified becomes true
  }
  fromFile.close(); //Closing the file
}

/*
 * Write all the elements of line_db into a file
 */

void LineManager::writeToDB() {
  cout << "Enter input file name:" << endl; //Message
  std::string fileName {this->getFileName()}; //Get the file name
  if(this->fileExist(fileName)){ //If the file exists
    std::ofstream toFile; //Creating an instance of output file stream
    toFile.open(fileName); //Opening file by getting the file name from user
    for(std::size_t index = 0; index < line_db.size(); index++){ //Looping through whole db
      line_db.moveToIndex(index); //Moving the current position
      toFile << line_db.getValue() << endl; //Writing into the file
    }
    toFile.close(); //Closing file after finishing writing
    this->isModified = false; //Since db is stored into a file so isModified becomes false to indicate the db has been written into a file
  }
  else {
    std::cerr << "Can't access the file!" << endl; //Showing error if file can't be opened
  }

}
/*
 * Print span of lines around current position
 */

void LineManager::printSpanOfLine() {
  std::size_t startingElement {line_db.getCurrentIndex() - this->upperSpan}; // Starting element to print. Assuming upper span is always in the range
  std::size_t endElement {this->lowerSpan + line_db.getCurrentIndex()}; // Last element to print. Assuming lowe span is always in the range
  std::size_t maxPossibleLowerSpan {line_db.size() - 1 - line_db.getCurrentIndex()}; // Finding the max lower span possible based on the position of cp
  std::string bof {}; //Message for upper span out of range. Initially empty
  std::string eof {};//Message for lower span out of range. Initially empty
  if(this->upperSpan > line_db.getCurrentIndex()){ //If upper span is out of range based on the position of cp
    bof = "**: BOF"; //Set up the out of range message
    startingElement =  0;//If the upper span is out of range then the starting element to print would be always the first element of the list
  }
  if(this->lowerSpan > maxPossibleLowerSpan){ //If lower span is out of range based on the position of cp
    eof = "**: EOF"; //Set up the out of range message
    endElement = line_db.size() - 1; //The end element to print will be the last element of the list
  }

  cout << bof << endl; //Printing the indication of upper span out of range
  while(startingElement <= endElement){ // Print from start to end position
    line_db.moveToIndex(startingElement); //moving the cp to point to the next
    cout << " " << startingElement + 1 <<  ":" << "\t" << line_db.getValue() << endl; //Printing the element(s) with their index
    startingElement++;
  }
  cout << eof << endl; //Printing the indication of lower span out of range
}

/*
 * Setting up upper and lower span
 */

void LineManager::setUpperLowerSpan() {
  cout << "What's the length of the span?" << endl; //Message
  int spanLength {this->getInt()}; //Initialize int to store length from user via getInt member function
  if(spanLength < 0){ //Set up upper span
    if(abs(spanLength) <= line_db.getCurrentIndex()){ //Check if desire upper span is possible
      this->upperSpan = abs(spanLength); //Change upper span to positive value of spanLength
    }
    else {
      cout << "That's a larger span of line. Max is " << line_db.getCurrentIndex() << endl; //If the upper span is larger than possible span
    }
  }
  else if(spanLength > 0){ //Set up lower span
    if(spanLength <= ((line_db.size() - 1) - line_db.getCurrentIndex())){ //Check if desire lower span is possible
      this->lowerSpan = spanLength; //Change lower span
    }
    else {
      cout << "That's a larger span of line. Max is " << (line_db.size() - 1) - line_db.getCurrentIndex() << endl; //If the lower span is larger than possible span
    }
  }
  else { //Set both span to zero if user inputs zero
    this->upperSpan = 0;
    this->lowerSpan = 0;
  }
}

/*
 * Deleting current line
 */

void LineManager::deleteCurrentLine() {
  line_db.remove(); //Removing the current line
  this->isModified = true; //DB has been updated
  cout << "Removing the current line...." << endl; //Message to display
}

/*
 * Print the current line
 */

void LineManager::printCurrentLine() const {
  cout << " " << line_db.getCurrentIndex() + 1 << ":" << '\t' << line_db.getValue() << endl; //Printing the cp with it's index
}

/*
 * Printing all the items in the list
 */
void LineManager::printAll() {
  cout << '\n';
  cout << line_db << endl; //Printing all the elements
}

/*
 * Move the current Line (CP) to desire line
 */

void LineManager::moveCP(){
  cout << "Which line to move to?" << endl; //Message
  int indexToMove {this->getInt()}; //Getting the index
  line_db.moveToIndex(--indexToMove); //Pre decrement the index to move, to match with 0-based indexing and pass it to line_db function moveToIndex
}


/*
 * Read the file name from the user
 * create an instance of ifstream to just read the file
 * open the file and return the ifstream
 */
std::ifstream LineManager::openFileToRead() const {
  cout << "Enter input file name:" << endl; //Message
  std::ifstream fromFile; //Initializing ifstream to only read from file
  fromFile.open(this->getFileName()); //Opening file by getting the file name from user
  return fromFile; //Returning the obj of ifstream
}

/*
 * Returns true if user's input start's with y / Y
 */
bool LineManager::ifYes() {
  std::string userResponse {this->getFileName()}; //Getting the string from user
  return std::toupper(userResponse.front()) == 'Y'; //Making the first character upper case to just match with Y
}

/*
 * Private member function to give user last chance to write to db
 */

void LineManager::writeToDBBeforeQuit() {
  if(this->isModified){ //If db has been modified but not written into any file
    cout << "Do you want to save changes to a file?" << endl; //Message
    if(this->ifYes()) //Making sure user's input contains Y/y in the first char of the string
      this->writeToDB(); //Writing into the file
  }
}

void LineManager::printWelcomeMsg(const std::string & msg) {
  cout << msg << endl; //Printing message
  for(std::size_t ch {0}; ch < msg.length(); ch++) //Underline as per the size of the message
    cout << "=";
  cout << endl;
}

/*
 * Set the options for both partial and full menu
 */
void LineManager::setMenu() {

  std::vector<std::string> menuItem {
    "Append input from the keyboard",
    "Insert input from the keyboard",
    "Append input from text file",
    "Insert input from text file",
    "Print the current line",
    "Print a span of lines around the current position",
    "Set the length of upper or lower line spans",
    "Print all",
    "Move the current line",
    "Delete the current line",
    "Write mini-database to file ",
    "Quit"
  };

  fullMenu.pushBack(menuItem); //Filling up full menu using pushBack(vector) member function

  for(std::size_t item {0}; item < menuItem.size(); item++){ //Filling up partial menu
    if(item < 4 || item >= 11) //Omit From 3 to 10 options
      partialMenu.pushBack(menuItem.at(item)); //Inserting into partial menu
  }
}

/*
 * Private member function to check if file exist before writing
 * creating ifstream to check if file exist so if not it does not create the file
 */

bool LineManager::fileExist(const std::string& fileName) {
  std::ifstream checkFile (fileName);
  return checkFile.good(); //Return true if exist
}

/*
 * Get and return the file name for from user
 * It keeps poping up until user inserts a name (not empty string) and if there is no space in the name
 */

std::string LineManager::getFileName() const{
  std::string fileName {};
  std::getline(cin, fileName); //Get the name
  while (fileName.empty()){ //Keeps popping up if the file name is empty
    cin.clear(); //Clear cin
    std::getline(cin, fileName); //Get the name again
  }
  return fileName; //Return file name
}

/*
 * A private member function
 * Getting integer from user for upper and lower span
 * */
int LineManager::getInt() const {
  int value{}; //To hold the value
  std::string garbage {}; //Clearing up the buffer
  cin >> value; //Reading value from user
  while(!cin){ //If not a valid input
    cin.clear(); //Clean up cin
    std::getline(cin, garbage); //Clean up buffer
    cin >> value; //Prompt again for the input
  }
  std::getline(cin, garbage); //Finally clear the buffer again
  return value; //Return value
}

/*
 * Getting the option number from user
 */


std::size_t LineManager::displayMenu() const {
  if(this->line_db.size()){ //If db is not empty
    return fullMenu.read_option_number(); //Full menu will be displayed and read option number from user
  } else{
    return partialMenu.read_option_number(); //Partial menu will be displayed if db is empty and read option number from user
  }
}

/*
 * Reading the string inserted by user
 * then return it
 */
std::string LineManager::getItemFromKeyBoard() const{
  std::string input {}; //String to get the input
  cin.clear(); // Clearing up the buffer
  getline(cin, input); //Getting the whole line
  return input; //Return the string
}

/*
 * Cleaning up the cin before getting the input line from user
 */
void LineManager::clearCin() const {
  while(cin && cin.get() != '\n'); //If there is something in the cin it's not a new line then keep reading
}

