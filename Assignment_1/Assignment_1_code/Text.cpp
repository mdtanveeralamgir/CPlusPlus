#include "Text.h"
#include <iostream>
#include <cstring>

using namespace std;

//Default constructor
Text::Text () : pStore{nullptr} {
  pStore = new char[1];
  *pStore = '\0';
}

//Copy constructor
Text::Text (const char *s) : pStore{nullptr} {
  if (s == nullptr) {
    this->pStore = new char[1];
    *pStore = '\0';
  } else {
    this->pStore = new char[std::strlen(s) + 1];
    std::strcpy(this->pStore, s);
  }
}

//Conversion constructor
Text::Text (const Text &source) : pStore{nullptr}{
  delete[] pStore;
  pStore = new char[strlen(source.pStore) + 1];
  std::strcpy(pStore, source.pStore);
}


//Destructor
Text::~Text () {
  delete[] pStore;
}

//Assignment operator overload
Text &Text::operator= (const Text &rhs) {
  if (this == &rhs) {
    return *this;
  } else {
    delete[] this->pStore;
    this->pStore = new char[strlen(rhs.pStore) + 1];
    std::strcpy(this->pStore, rhs.pStore);
    return *this;
  }
}

//Assign c-string to this obj
void Text::assign (const char *value) {
  strcpy(pStore, value);

}

//Assign Text to this obj
void Text::assign (const Text &value) {
  pStore = value.pStore;

}

//Append char to this obj
void Text::append (const char *value) {
  char *temp(pStore);
  delete [] this->pStore;
  pStore = new char[strlen(pStore) + strlen(value) + 1];
  strcpy(pStore, temp);
  std::strcat(pStore, value);
}


//Append Text to this obj
void Text::append (const Text &source) {
  char *temp(pStore);
  delete [] this->pStore;
  pStore = new char[strlen(pStore) + strlen(source.pStore) + 1];
  strcpy(pStore, temp);
  strcat(pStore, source.pStore);
}

//Clear
void Text::clear () {
  pStore = nullptr;
}

//Returns the length of PStore
int Text::length () const {
  return strlen(pStore);
}


//Verifies if the Text obj's C-string is 0 or positive
bool Text::isEmpty () const {
  if (length()) {
    return true;
  } else {
    return false;
  }
}

//Returns pointer to the pStore
const char *Text::getCstring () const {
  return pStore;
}

//Insertion operation overload
std::ostream &operator<< (std::ostream &sout, const Text &txt) {
  sout << txt.getCstring();


  return sout;
}

