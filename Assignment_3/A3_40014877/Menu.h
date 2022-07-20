#ifndef A3_40014877_MENU_H
#define A3_40014877_MENU_H
#include <string>
#include <vector>
#include <iterator>
using std::string;

class Menu {
private:
  std::string topMessage {"Choose one of the following options:"}; //declare and initialize default value for topMessage
  std::string bottomMessage {"Enter an option number"}; //declare and initialize default value for bottomMessage
  std::vector<string> optionList {}; //Declare and initialize optionList
public:
    Menu() = default; //Default constructor with default value for top and bottom message
    Menu(const Menu&) = delete; //Default copy constructor
    Menu & operator=(const Menu&) = delete; //Default assignment overload
    ~Menu() = default; //Default destructor
    void pushBack(const string &); //Adding item at the end of the list
    void pushBack(const std::vector<string> & rhs); //Inserting elements from a vector
    void insertItem(size_t, const string&); //Insert item into the vector at a given position
    void remove(std::size_t); //Remove item from a given position
    void popBack();//Remove item from the end of the vector
    string get(std::size_t) const; //Return an item from vector at index th position
    string toString() const; //Convert the whole vector to a string
    void setTopMessage(const string&); //Setting up top message
    void setBottomMessage(const string&); //Setting up bottom message
    void clearTopMessage(); //Remove top message
    void clearBottomMessage(); //Remove bottom message
    bool isEmpty() const; //Check if the vector is empty
    size_t read_option_number() const; //Read the option number from user
    size_t size() const; //Returns the size of the vector
};

#endif //A3_40014877_MENU_H
