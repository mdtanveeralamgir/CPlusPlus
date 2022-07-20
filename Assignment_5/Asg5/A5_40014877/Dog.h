#ifndef A5_40014877_DOG_H
#define A5_40014877_DOG_H
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <functional>
#include <set>
using std::string;
using std::cout;
using std::endl;
/*
 * section 2.1
 * minimal representation of Dog class
 */
class Dog {
    //Member variables
    std::string name;
    std::string breed;
    std::string age;
    std::string gender;

public:
    Dog() = default;
    Dog(const Dog& ) = default;
    Dog& operator=(const Dog& ) = default;
    ~Dog() = default;
    Dog( Dog&&) = default;
    Dog& operator=( Dog&&) = default;
    Dog(std::string n, std::string b, std::string a, std::string g);
    friend std::ostream &operator<<(std::ostream &, const Dog&); //Overloading ostream
    friend std::istream &operator>>(std::istream &, Dog &); //Overloading istream

    //Getter setter for member variables
    const string &getName () const;
    void setName (const string &name);
    const string &getBreed () const;
    void setBreed (const string &breed);
    const string &getAge () const;
    void setAge (const string &age);
    const string &getGender () const;
    void setGender (const string &gender);
};
using DogMapDefault = std::multimap<string, Dog>;
std::ostream &operator<<(std::ostream &sout, const Dog &dog);

//Overloading << operator to display Dog obj in the multimap
template<typename comp>
std::ostream &operator<<(std::ostream & sout, const std::multimap<string, Dog, comp> & dogmap);

//Trim leading and trailing spaces
string trimWithLoop(const string & str); //Task 1

/*
 * 3.1 task 1
 * trim without using any loops
 */
string trim(const string & str);

/*
 * Section 2.3 to 2.7
 *
 */

/*
 * 3.2
 * Task 2
 * loading csv file using for_each
 */

void load_csvFile_for_each(DogMapDefault& dog_map, std::string filename);

/*
 * 3.3
 * Task 3
 * Loading csv file using transform
 */

void load_csvFile_for_transform(DogMapDefault& dog_map, std::string filename);

/*
* 3.4
* Task 4
* Displaying dog objects using great<string>
*/

 template<typename comp>
 std::ostream &operator<<(std::ostream & sout, const std::multimap<string, Dog, comp> & dogmap) {
   for (const auto &dog : dogmap) {
     std::cout << std::setw(25) << dog.first << " --> " << dog.second << std::endl;
   }
   return sout;
 }

template<typename comp>
void load_csvFile_Normal_Loop(std::multimap<string, Dog, comp> & , std::string);

//Normal loop (while) to get the data from csv file and insert into dog_map
//template <typename DogMapType> //std::multimap<string, Dog, std::greater<string>>
template<typename com>
void load_csvFile_Normal_Loop(std::multimap<string, Dog, com> & dog_map, std::string filename) {
  std::ifstream input_file_stream(filename); // Create an input file stream if (!input_file_stream.is_open()) { // Check that the file is open
  if(!input_file_stream.is_open()){
    cout << "Could not open file " + filename << endl;
    throw std::runtime_error("Could not open file " + filename);
  }
  std::string line;
  while (std::getline(input_file_stream, line)) {
    std::stringstream my_line_stream(line); // turn the line into an input stream
    Dog dog{};
    my_line_stream >> dog; // initialize dog using Dog’s operator>>
    dog_map.emplace(dog.getBreed(), dog); // insert dog into dog_map
  }
  input_file_stream.close(); // Close file
}

/*
 * 3.5
 * Task 5
 */
DogMapDefault findBreedRange(DogMapDefault &source, const std::string &key_breed);

//taks 4
bool is_palindrome(string);
void test_is_palindrome();

//task 5
void test_second_max(std::vector<int> vec);
template<typename Iterator>
std::pair<Iterator, bool> second_max(Iterator start, Iterator end){
  Iterator firstItr{start};
  Iterator max{start};
  Iterator result{start};
  bool isEqual {false};

  //Empty
  if(start == end){
      result = end;
  }
  else if(start != end){
    firstItr++;
    while(firstItr != end){
      if(*firstItr > *max){
        max = firstItr;
        isEqual = true;
      }
      ++firstItr;
    }
    firstItr = start;
    while(firstItr != end){
      if(*firstItr != *max && *result < *firstItr)
        result = firstItr;
      firstItr++;
    }
  }

  return std::make_pair(result, isEqual);
}

/*
 * Task 6
 */

//Using lambda
int testCountStringLambda(const std::vector<string> &, int);

//Using Free function
int testCountStringFreeFun(const std::vector<string> &, int);
bool equalOf(const string &, int);

//Using fanctor
struct countSring{
    int counter{};
    countSring(int n):counter{n}{}

    bool operator()(const string & str){return str.length() == counter;}
};

int testCountStringsFunctor(const std::vector<string> &, int);

/*
 * task 7
 */


void multisetUsingDefaultComparator(); //Default comparison function

//functor for the custom comparison function
template <class T>
struct com : std::binary_function <T,T,bool> { //Takes 2 param of same type and return bool
    bool operator() (const T& x, const T& y) const { //operator () overload
     if(x.length() == y.length()){ //If the length is same then compare the strings
       return x < y;
     } else if(x.length() < y.length()){ //Else compare only the length of 2 strings
       return true;
     }
    }
};


template<typename T>
void multisetUsingMyComparator(){
  std::multiset<std::string, com<T>> strSet;
  std::vector<std::string> vec {"C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };
  std::copy(vec.begin(), vec.end(), std::inserter(strSet, strSet.begin()));
  std::ostream_iterator<std::string> out(cout, " ");
  std::copy(strSet.begin(), strSet.end(), out);
}

#endif //A5_40014877_DOG_H
