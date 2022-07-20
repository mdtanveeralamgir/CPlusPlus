
#ifndef OPERATIONOVERLOAD_MENU_H
#define OPERATIONOVERLOAD_MENU_H
#include "Text.h"
using namespace std;
class Menu {
private:
    Text *optionList;
    int capacity;
    int count;
    Text topMessage;
    Text bottomMessage;
    void doubleCapacity();

public:
    Menu();
    Menu(const Menu &source);
    virtual ~Menu();
    Menu &operator=(const Menu &rhs);
    void insert(int index, Text &value);
    void insert(int index, const char *value);
    void pushBack(const char *value);
    void pushBack(const Text &value);
    void remove(int index);
    int size() const;
    int getCapacity() const;
    void popBack();
    Text get(int value);
    Text toString();
    int readOptionNumber();
    void setTopMessage(const Text &source);
    void setBottomMessage(const Text &source);
    void clearTopMessage();
    void clearBottomMessage();
    bool isEmpty();
    void display();



};

ostream& operator<<(ostream &, Menu&);


#endif //OPERATIONOVERLOAD_MENU_H
