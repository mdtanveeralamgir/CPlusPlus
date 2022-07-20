#include "Menu.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
using std::cin;
using std::string;
using std::cout;
using std::endl;


/*
 * Pushing a single item at the end of the vector
 */
void Menu::pushBack(const string & singleOption) {
  optionList.push_back(singleOption); // Pushing an item using push_back function of vector
}

/*
 * Adding a new vector to the end of the optionList
 */
void Menu::pushBack(const std::vector<string> &rhs) {
  for(auto option: rhs){
    optionList.push_back(option); // Adding each element of passing vector to optionList
  }
}

/*
 * Insert an item at given index position
 */
void Menu::insertItem(size_t index,const string& singleOption) {
  if(index  && index <= this->size()){ //Make sure index is not zero and not more than vector size
    --index; // Decrementing index by 1 to match the indexing
    //this->setIterator(index);
    optionList.insert(optionList.begin() + index, singleOption); //Get to the desire index by adding index parameter
  } else{
    cout << "Invalid index to insert into" << endl;
  }
}

/*
 * Remove an item from given position
 */

void Menu::remove(size_t index) {
  if(index  && index <= this->size()){ //Make sure index is not zero and not more than vector size
    --index; // Decrementing index by 1 to match the indexing
    optionList.erase(optionList.begin() + index); //Get to the desire index by adding index parameter
  }
}

/*
 * Return an item from vector at index th position
 */

string Menu::get(size_t index) const{
  if(index  && index <= this->size()) //Make sure index is not zero and not more than vector size
    return *(optionList.begin() + (--index)); //Getting to the position by adding decremented value of index
  else
    return "Invalid index to insert into";
}

/*
 * Return the string format of the menu
 */
string Menu::toString() const{
  std::string vecToString{}; //String to store menu
  size_t count{1}; // User based indexing
  vecToString += this->topMessage + "\n"; // Adding top message
  for (auto op: this->optionList) { //Iterate through vector
    vecToString += "\t"; //Adding tab
    vecToString += std::to_string(count); //Casting and adding index
    vecToString += ". ";
    vecToString += op; //Adding items from optionList
    vecToString += "\n";
    count++;
  }
  vecToString += this->bottomMessage + "\n"; //Adding bottom message
  vecToString += "?? ";

  return vecToString;
}

/*
 * setting up Top Message
 */
void Menu::setTopMessage(const std::string& t_message) {
  this->topMessage = t_message;
}

/*
 * setting up Bottom Message
 */
void Menu::setBottomMessage(const std::string& b_message) {
  this->bottomMessage = b_message;
}

/*
 * Clear Top Message
 */

void Menu::clearTopMessage() {
  this->topMessage.clear();
}

/*
 * Clear Bottom Message
 */

void Menu::clearBottomMessage() {
  this->bottomMessage.clear();
}

/*
 * Return true if vector's size is 0
 * This function is not necessary since for vector we have already an empty() function
 * Still adding this to fulfill with the assignment 1 requirements
 */
bool Menu::isEmpty() const {
  return optionList.empty();
}
/*
 * Removing an item from the back of the vector
 */

void Menu::popBack() {
  optionList.erase(optionList.end() - 1); // Erasing the last element
}

/*
 * Return the current size of the vector
 */
size_t Menu::size() const {
  return optionList.size();
}

/*
 * Read and return option number from user
 */
size_t Menu::read_option_number() const{
  size_t optionNumber{}; //Option number should always be positive
  string invalidInput{}; //To clean the invalid input
  cout << this->toString(); //Printing the menu
  cin >> optionNumber; //Reading the desire option number
  while (!cin){ //If the input from user is not valid
    cout << this->toString(); //Print the menu again
    cin.clear(); //Clear cin
    std::getline(cin, invalidInput); //Clean up the buffer
    cin >> optionNumber; //Again read option number
  }
  return optionNumber; //Return option number
}
