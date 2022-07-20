#include "Dog.h"
/*
 * Section 2.2
 * Implementation of section 2.1
 */
//Constructor
Dog::Dog(std::string n, std::string b, std::string a, std::string g)
:name(n), breed(b), age(a), gender(g) {}

//Overloading << operator to display dog obj
std::ostream &operator<<(std::ostream &sout, const Dog &dog) { //Overloading ostream operator
  sout << dog.name << ", " << dog.breed << ", " << dog.age << ", " << dog.gender;
  return sout;
}


//printing from the map of dog object
std::ostream &operator<<(std::ostream & sout, const std::multimap<string, Dog> & dogmap) {
  for (const auto &dog : dogmap) {
    std::cout << std::setw(25) << dog.first << " --> " << dog.second << std::endl;
  }
  return sout;
}



const string &Dog::getName () const {
  return name;
}

void Dog::setName (const string &name) {
  Dog::name = name;
}

const string &Dog::getBreed () const {
  return breed;
}

void Dog::setBreed (const string &breed) {
  Dog::breed = breed;
}

const string &Dog::getAge () const {
  return age;
}

void Dog::setAge (const string &age) {
  Dog::age = age;
}

const string &Dog::getGender () const {
  return gender;
}

void Dog::setGender (const string &gender) {
  Dog::gender = gender;
}

//Inserting into istream
std::istream &operator>>(std::istream &sin, Dog &dog) {
// your task: validate input. (you may use std::regex but are not required to)
// If invalid, throw std::runtime_error("Invalid input line "); // trim() removes
  std::getline(sin, dog.name, ',');
  dog.name = trim(dog.name);
  std::getline(sin, dog.breed, ',');
  dog.breed = trim(dog.breed);
  std::getline(sin, dog.age, ',');
  dog.age = trim(dog.age);
  std::getline(sin, dog.gender);
  dog.gender = trim(dog.gender);
  return sin;
}

/*
 * trim leading and trailing white spaces using loops
 *
 */

//Trimming leading and trailing whitespaces
string trimWithLoop(const string & str){
  string result{str};

  for(int i {0}; i < result.length(); i++){
    if(!isspace(result[i])){
      result.erase(0, i);
      break;
    }
  }
  for(int j {int(result.length() - 1)}; j >= 0; j--){
    if(!isspace(result[j])) {
      result.erase(j+1, int(result.length() - 1));
      break;
    }
  }
  return result;
}

/*
 * Task 1
 * Recreating trim without using an explicit loop(s)
 */
string trim(const string & str){
  string result{str};
  result.erase(0, result.find_first_not_of(" ")); //Removing whitespace(s) from the beginning
  result.erase(result.find_last_not_of(" ") + 1, result.length() - 1); //Removing whitespaces from the end of the string
  return result;
}
//**************************************************************************



/*
 * Task 2
 * Replacing while loop with for_each to get data from csv and insert into dog_map
 */
void load_csvFile_for_each(DogMapDefault& dog_map, std::string filename) {
  std::ifstream input_file_stream(filename); // Create an input file stream if (!input_file_stream.is_open()) { // Check that the file is open
  if(!input_file_stream.is_open()){
    cout << "Could not open file " + filename << endl;
    throw std::runtime_error("Could not open file " + filename);
  }
  std::istream_iterator<Dog> input_start(input_file_stream);
  std::istream_iterator<Dog> input_finish{};
  std::for_each(input_start, input_finish, [&](Dog d){dog_map.emplace(d.getBreed(), d);});
  input_file_stream.close(); // Close file
}

//**************************************************************************

/*
 * Task 3.4
 *
 * Replacing while loop with transform to get data from csv and insert into dog_map
 */
void load_csvFile_for_transform(DogMapDefault& dog_map, std::string filename) {
  std::ifstream input_file_stream(filename); // Create an input file stream if (!input_file_stream.is_open()) { // Check that the file is open
  if(!input_file_stream.is_open()){
    cout << "Could not open file " + filename << endl;
    throw std::runtime_error("Could not open file " + filename);
  }
  std::istream_iterator<Dog> input_start(input_file_stream);
  std::istream_iterator<Dog> input_finish{};
  DogMapDefault::iterator it = dog_map.begin();
  std::insert_iterator<DogMapDefault> insert_it (dog_map, it);
  std::transform(input_start, input_finish, insert_it, [&](Dog d){return std::pair<string, Dog>(d.getBreed(), d);});
  input_file_stream.close(); // Close file
}

/*
 * Task 3.5
 * Task 5
 */

DogMapDefault findBreedRange(DogMapDefault & source, const std::string &key_breed){
  DogMapDefault temp{};
  std::pair <DogMapDefault::iterator, DogMapDefault::iterator> dogPair;
  dogPair = source.equal_range(key_breed);

  for (DogMapDefault::iterator it=dogPair.first; it!=dogPair.second; ++it){
    temp.emplace(it->first, it->second);
  }

  return  temp;
}

/*
 * Section 4
 * Palindromes and No Explicit Loops
 */

//Free function
bool is_appha(char ch){
  return !std::isalpha(ch);
}

bool is_palindrome(string input){
  std::vector<char> temp{};
  string::iterator it = input.begin();
  string::iterator it_end = input.end();

  std::remove_copy_if(it, it_end, std::back_inserter(temp), is_appha);

  std::transform(std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()), temp.begin(), [](char ch){return toupper(ch);});
  std::vector<char>::iterator end = temp.begin();
  std::advance(end, floor(temp.size()/2));
  return std::equal(temp.begin(), end, temp.rbegin());
}

void test_is_palindrome() {
  std::string str_i = std::string("was it a car or A Cat I saW?");
  std::string str_u = std::string("was it A Car or a cat U saW?");
  cout << "the phrase \"" + str_i + "\" is " +
          (is_palindrome(str_i) ? "" : "not ") + "a palindrome\n";
  cout << "the phrase \"" + str_u + "\" is " +
          (is_palindrome(str_u) ? "" : "not ") + "a palindrome\n";
}

/*
 * 5
 * Searching for the Second Max
 */

void test_second_max(std::vector<int> vec){
  auto retval = second_max(vec.begin(), vec.end());
  if (retval.second) {
    cout << "The second largest element in vec is " << *retval.first << endl;
  }
  else
  {
    if (retval.first == vec.end())
      cout << "List empty, no elements\n";
    else
      cout << "Container’s elements are all equal to " << *retval.first << endl;
  }
}

/*
 * 6
 * Counting Strings of Equal lengths in a Vector
 */

//Using lambda
int testCountStringLambda(const std::vector<string> & vec, int counter){
   return std::count_if(vec.begin(), vec.end(), [&](string str){return str.length() == counter;});
}

//Using free function
bool equalOf(const string & str, int counter){
  return str.length() == counter;
}

int testCountStringFreeFun(const std::vector<string> & vec, int counter){
  using namespace std::placeholders;
  auto func = std::bind(equalOf,_1,counter);
  return std::count_if(vec.begin(), vec.end(), func);
}


//Using functor
int testCountStringsFunctor(const std::vector<string> & vec, int counter){
  return std::count_if(vec.begin(), vec.end(), countSring(counter));
}

/*
 * 7
 * Sorting Strings on length and Value
 */

void multisetUsingDefaultComparator(){
  std::multiset<std::string> strSet;
  std::vector<std::string> vec {"C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };
  std::copy(vec.begin(), vec.end(), std::inserter(strSet, strSet.begin()));
  std::ostream_iterator<std::string> out(cout, " ");
  std::copy(strSet.begin(), strSet.end(), out);
}


