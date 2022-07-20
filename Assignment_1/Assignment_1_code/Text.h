#ifndef OPERATIONOVERLOAD_TEXT_H
#define OPERATIONOVERLOAD_TEXT_H
#include <fstream>
class Text {
private:
    char *pStore;
public:
    Text();
    Text(const char *s);
    Text(const Text &source);
    virtual ~Text();
    //Copy assignment
    Text &operator=(const Text &rhs);
    void display() const;
    int length() const;
    const char *getCstring() const;
    void assign(const char*);
    void assign(const Text&);
    void append(const char *value);
    void append(const Text &source);
    void clear();
    bool isEmpty() const;

};

std::ostream& operator<<(std::ostream & sout, const Text& t);
#endif //
