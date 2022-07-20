//
// Created by Md Tanveer Alamgir on 2020-05-24.
//

#include "Menu.h"
#include <iostream>
#include <cstring>
#include <cctype>

Menu::Menu ()
        : optionList{}, capacity{1}, count{0}, topMessage{}, bottomMessage{} {
  optionList = new Text[capacity];

}

Menu &Menu::operator= (const Menu &rhs) {
  if (this != &rhs) {
    delete[] optionList;
    optionList = new Text[rhs.getCapacity()];
    for (size_t i{0}; i < rhs.getCapacity(); ++i) {
      optionList[i] = rhs.optionList[i];
    }

  }
  return *this;
}

int Menu::getCapacity () const {
  return this->capacity;
}

int Menu::size () const {
  return count;
}

void Menu::setBottomMessage (const Text &source) {
  this->bottomMessage = source;
}

void Menu::setTopMessage (const Text &source) {
  this->topMessage = source;
}


//Display the menu and reads user's input
int Menu::readOptionNumber () {
  int input{};
  cin >> input;

  while (true) {
    if (!cin) {
      cout << this->toString() << endl;
      cin.clear();
      cin.ignore(256, '\n');
    } else if (input > this->count || input < 0) {
      cout << this->toString() << " ";
      cout << input << endl;
      cout << "Invalid choice " << input << "." << " It must be in range " << "[1, " << count << "]\n";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      break;
    }
    cin >> input;
  }

  return input;
}

void Menu::pushBack (const char *value) {

  if (this->size() == this->getCapacity()) {
    this->doubleCapacity();
  }
  Text temp(value);
  this->optionList[count] = temp;
  ++count;
}

void Menu::insert (int index, const char *value) {
  int indexCount{0};
  --index;
  if (this->size() == this->getCapacity()) {
    this->doubleCapacity();
  }
  //Text *temp = new Text[this->size() + 1];
  Text *temp = new Text[this->getCapacity()];

  for (size_t i{0}; i < this->size(); ++i) {
    if (i == index) {
      temp[i] = value;
      this->count++;
    } else {
      temp[i] = this->optionList[indexCount];
      ++indexCount;
    }
  }
  delete[] this->optionList;
  this->optionList = temp;

}

void Menu::insert (int index, Text &value) {
  int indexCount{0};
  if (this->size() == this->getCapacity()) {
    this->doubleCapacity();
  }
  Text *temp = new Text[this->getCapacity()];

  for (size_t i{0}; i < this->size(); ++i) {
    if (i == index) {
      temp[i] = value;
      this->count++;
    } else {
      temp[i] = this->optionList[indexCount];
      ++indexCount;
    }
  }
  delete[] this->optionList;
  this->optionList = temp;
}

void Menu::remove (int index) {
  --index;
  int indexCount{0};
  Text *temp = new Text[this->getCapacity()];

  for (size_t i{0}; indexCount < this->getCapacity(); ++i) {
    if (i == index) {
      temp[i] = this->optionList[++indexCount];
    } else {
      temp[i] = this->optionList[indexCount];
    }
    indexCount++;
  }
  delete[] this->optionList;
  this->optionList = temp;
  this->count--;
}

void Menu::popBack () {
//  Text *temp = new Text[this->getCapacity()];
//  for (size_t i{0}; i < this->size() - 1; ++i) {
//    temp[i] = this->optionList[i];
//  }
//  delete[] this->optionList;
//  this->optionList = temp;
//  count--;
this->optionList[count - 1] = nullptr;
count--;
}

Text Menu::get(int value) {
  return this->optionList[--value];
}

void Menu::clearTopMessage () {
  this->topMessage = nullptr;
}

void Menu::clearBottomMessage () {
  this->bottomMessage = nullptr;
}

void Menu::doubleCapacity () {
  int twice_cap = 2 * this->getCapacity();  // new desired capacity
  Text *temp = new Text[twice_cap];         // allocate space twice the current capacity

  for (std::size_t i = 0; i < this->getCapacity(); i++) // assign current option list to temp, element by element
  {
    temp[i] = this->optionList[i];   // Text's operator= performs the assignment
  }
  delete[] this->optionList;         // release current storage
  this->optionList = temp;          // point at new storage
  this->capacity = twice_cap;     // adjust capacity
}


//Option list is empty or not
bool Menu::isEmpty () {
  if (count > 0) {
    return false;
  } else {
    return true;
  }
}

//Test display menu
void Menu::display () {
  cout << this->topMessage << endl;
  cout << this->bottomMessage << endl;
  for (int i{0}; i < this->size(); i++) {
    cout << this->optionList[i] << endl;
  }
}

Text Menu::toString () {
  Text *displayMenu = new Text;
//  displayMenu->append(topMessage);
  cout << this->topMessage << endl;
  displayMenu->append("\n");
  for (int i{0}; i < this->size(); i++) {
    displayMenu->append("\t");
//    cout << this->optionList[i] << endl;
    displayMenu->append(this->optionList[i]);
    displayMenu->append("\n");
  }
  displayMenu->append(bottomMessage);
//  cout << this->bottomMessage << endl;
  displayMenu->append("\n");
  displayMenu->append("?? ");

  return *displayMenu;
}

//Insertion operation overload
std::ostream &operator<< (std::ostream &sout, Menu &source) {
  sout << source.toString() << endl;

  return sout;
}

Menu::~Menu () {
  delete[] optionList;
}

