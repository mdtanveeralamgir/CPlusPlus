#include <iostream>
#include "Text.h"
#include "Menu.h"

using namespace std;

int main () {
//Test for Text class
/*
  Text t1;
  Text t2("quick brown fox");
  Text t3{t2};
// defalt constructor
// conversion constructor
// copy constructor
  cout << "t1: " << t1 << endl; // operator<< overload
  cout << "t2: " << t2 << endl;
  cout << "t3: " << t3 << endl;
  t1.append("The "); // append a given C-string to t1’s C-string
  cout << "t1: " << t1 << endl;
  t1.append(t2); // append t2’s C-string to t1’s C-string
  cout << "t1: " << t1 << endl;
  t2 = Text(" jumps over ");   // assignment operator overload
  cout << "t2: " << t2 << endl;
  t3.assign("a lazy dog"); // assign a given C-string to t3’s C-string
  cout << "t3: " << t3 << endl;
  t1.append(t2); // assign t2’s C-string to t1’s C-string
  cout << "t1: " << t1 << endl;
  t1.append(t3); // append t3’s C-string to t1’s C-string
  cout << "t1: " << t1 << endl;
  */
//*******************************************************

/*
 * Create and print an empty menu
 * Requirement 1 and 2
 * Making toString and operation overload work
 */

  Menu menu;
//  cout << menu << endl;

//*******************************************************
  /*
   * Requirement 3
   * Making menu.readOptionNumber() works
   * Retrieve choice
   */

//  int choice = menu.readOptionNumber();
//  cout << "You entered " << choice << endl;

//*******************************************************

  /*
   * Requirement 4
   * Adding a value at the back of the array
   * Making pushBack function work
   */

//  menu.pushBack("Pepsi");
//  cout << menu << endl;

//*******************************************************

  /*
   * Requirement 5
   * Add couple of more options by calling pushBack
   * And retrieve value entered by user using menu.readOptionNumber();
   */

//  menu.pushBack("Pepsi");
//  menu.pushBack("Apple juice");
//
//  menu.pushBack("Root beer");
//  cout << menu << endl;
//
//  int choice = menu.readOptionNumber();
//  cout << "You entered " << choice << endl;

//*******************************************************

  /*
   * Requirement 6
   * Set top and bottom message using setTopMessage() and SetBottomMessage()
   *
   */

//  menu.setTopMessage("Choose your thirst crusher");
//  menu.setBottomMessage("Enter a drink number");
//  menu.pushBack("Pepsi");
//  menu.pushBack("Apple juice");
//  menu.pushBack("Root beer");
//  menu.pushBack("Root beer");
//  cout << menu << endl;
//  int choice = menu.readOptionNumber();
//  cout << "You entered " << choice << endl;

//*******************************************************

/*
 * Requirement 7
 * Remove the last option using popBack()
 * Insert an option at option 2 using insert()
 */

//  menu.setTopMessage("Choose your thirst crusher");
//  menu.setBottomMessage("Enter a drink number");
//  menu.pushBack("Pepsi");
//  menu.pushBack("Apple juice");
//  menu.pushBack("Root beer");
//  menu.popBack();
//  menu.insert(2, "Iced team with lemon");
//  cout << menu << endl;
//  int choice = menu.readOptionNumber();
//  cout << "You entered " << choice << endl;

//*******************************************************

/*
 * Requirement 8
 * Remove number 1 option using remove() method
 */
//  menu.setTopMessage("Choose your thirst crusher");
//  menu.setBottomMessage("Enter a drink number");
//  menu.pushBack("Pepsi");
//  menu.pushBack("Apple juice");
//  menu.pushBack("Root beer");
//  menu.popBack();
//  menu.insert(2, "Iced team with lemon");
//  menu.popBack();
//  menu.remove(1);
//  cout << menu << endl;
//  int choice = menu.readOptionNumber();
//  cout << "You entered " << choice << endl;

  //*******************************************************

  /*
   * Requirement 9
   * Remove the last option
   */

//  menu.setTopMessage("Choose your thirst crusher");
//  menu.setBottomMessage("Enter a drink number");
//  menu.pushBack("Pepsi");
//  menu.pushBack("Apple juice");
//  menu.pushBack("Root beer");
//  menu.popBack();
//  menu.insert(2, "Iced team with lemon");
//  menu.popBack();
//  menu.remove(1);
//  menu.popBack();
//  cout << menu << endl;
//  int choice = menu.readOptionNumber();
//  cout << "You entered " << choice << endl;

  //*******************************************************

  /*
   * Requirement 10 (Final)
   * Clear top and bottom message
   */

  menu.setTopMessage("Choose your thirst crusher");
  menu.setBottomMessage("Enter a drink number");
  menu.pushBack("Pepsi");
  menu.pushBack("Apple juice");
  menu.pushBack("Root beer");
  menu.popBack();
  menu.insert(2, "Iced team with lemon");
  menu.popBack();
  menu.remove(1);
  menu.popBack();


  //Implementation of final step
  menu.clearBottomMessage();
  menu.setTopMessage("Who Says You Can’t Buy Happiness?\n Just Consider Our Seriously Delicious Ice Cream Flavors");
  menu.setBottomMessage("Enter the number of your Happiness! ");
  menu.pushBack("Bacon ice cream!");
  menu.pushBack("Strawberry ice cream");
  menu.pushBack("Vanilla ice cream");
  menu.pushBack("Chocolate chip cookie dough ice cream");
  cout << menu << endl;
  int choice = menu.readOptionNumber();
  cout << "You entered " << choice << endl;


  return 0;
}
