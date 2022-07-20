#ifndef A3_40014877_MINIDB_H
#define A3_40014877_MINIDB_H
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>

using std::list;
using std::cout;
using std::endl;

template <typename dataType>
class MiniDB {
private:
    list<dataType> db_store {}; //declaring list of any type
    typename list<dataType>::const_iterator cp {db_store.end()}; //Declaring iterator of the list type
public:
  MiniDB() = default; //Default constructor
  MiniDB(const MiniDB<dataType> &) = default; //Default copy constructor
  MiniDB<dataType> & operator=(const MiniDB<dataType>&) = default; //Default assignment operator
  virtual ~MiniDB() = default; //Default destructor
  size_t size() const; //Current size of the list
  void insert(const dataType &); //Insert an element at the current position
  void append(const dataType &); //Append element at the end of the list
  void prev(); //Move the cp one step back
  void next(); //Move the cp one step forward
  dataType remove(); //Remove the element cp is pointing to and return the removed element
  void moveToFirst(); //Move the cp to first element
  void moveToLast(); //Move the cp to last element
  size_t getCurrentIndex() const; //Get the index of cp pointing to
  void moveToIndex(size_t); //Move the cp to a specific index
  dataType getValue() const;//Get the value of element cp is pointing to
  void toStream(std::ostream&); //Inserting list elements into ostream to print
};

  /*
   * Returns the number of items in the database

   */
  template <typename dataType>
  size_t MiniDB<dataType>::size() const{
    return db_store.size();
  }

  /*
   * Inserts a given item at where cp points at
   * The implementation of cp to move to last element added is in the LineManager::insertItem.
   * Since there could be the case where multiple line may be added
   */
  template <typename dataType>
  void MiniDB<dataType>::insert(const dataType & item){
    if(db_store.empty()){ //When the list is empty I just append
      db_store.push_back(item);
    } else {
      db_store.insert(cp, item); //Else insert the item before cp
    }
  }

  /*
  * Appends a given item at the end of the list.
  */
  template <typename dataType>
  void MiniDB<dataType>::append(const dataType & item){
    db_store.push_back(item); //Push back the new item
    this->moveToIndex(this->size() - 1); //After append the cp will point to the last element of the list
  }

  /*
   * If cp is pointing to the first element then throws an logic_error
   * If cp is not pointing to the first element then the list is not empty since in an empty list the begin() and end() refers to the same position
   * Else moves the cp one step backward
   */
  template <typename dataType>
  void MiniDB<dataType>::prev(){
    if(cp == db_store.begin())
      throw std::logic_error("CP is pointing to the first element of the list");
    cp--;
  }

    /*
     * If cp is pointing to the last element then throws an logic_error
     * Else moves the cp one step forward
     */
    template <typename dataType>
    void MiniDB<dataType>::next(){
      if(cp == std::prev(db_store.end(), 1)) //Since cp pointing to the last element not the end of list
        throw std::logic_error("Already pointing to the last element of the list");
      cp++;
    }

    /*
     * Remove the item cp pointing to
     * Move the cp forward
     * then check if
     * Else list is empty and cp will be pointing to the end();
     */

    //The erase function erases the element pointed by cp and return the pointer to next element
    template <typename dataType>
    dataType MiniDB<dataType>::remove(){
      if(db_store.empty())
        throw std::logic_error("The list is empty");
      dataType tempValue = *cp;
      cp = db_store.erase(cp); //After erasing erase function returns the pointer of next element. Which is assigned to cp

      if(!db_store.empty() && cp == db_store.end()) //If db is not empty and cp is not pointing to the end
        this->prev(); //Move one position back
      return tempValue; //Return the removed item
    }

    /*
     * cp moves to the first element
     */
    template <typename dataType>
    void MiniDB<dataType>::moveToFirst(){
      if(db_store.empty()) //If the list is empty throws an error
        throw std::logic_error("The list is empty");
      cp = db_store.begin(); //cp pointing at the beginning of the list
    }

    /*
     * cp moves to the last element
     */
    template <typename dataType>
    void MiniDB<dataType>::moveToLast(){
      if(db_store.empty())//If db is empty throws logic error
        throw std::logic_error("The list is empty");
      cp = std::prev(db_store.end(), 1); //Else move the cp to point to last item
    }

    /*
     * Returns the index of element cp points at
     */
    template <typename dataType>
    size_t MiniDB<dataType>::getCurrentIndex() const{
      if(db_store.empty()) //If db is empty throws logic error
        throw std::logic_error("DB has zero element");
      return std::distance(db_store.begin(), cp); // 0 based indexing
    }

    /*
     * Move cp to a specific index
     */
    template <typename dataType>
    void MiniDB<dataType>::moveToIndex(std::size_t index){
      if(db_store.empty()) //If db is empty throws logic error
        throw std::logic_error("The list is empty");
      if(index >= 0 && index < this->size()){ //Make sure the requesting index is valid
        std::advance(cp, int(index - this->getCurrentIndex())); //If index is greater than current position then cp will go forward else current position will go backward
      } else {
        throw std::logic_error("Not a valid index"); //If the requesting position is not valid based on the db size then throws logic error
      }
    }

    /*
     * Return the value of cp
     */
    template <typename dataType>
    dataType MiniDB<dataType>::getValue() const{
      if(this->cp == db_store.end()) //If cp is pointing to the end of the list it will throw logic error since there is no item in the end of the list
        throw std::logic_error("The list is empty");
      return *cp;
    }

    /*
     * toStream to put the list items in the output stream
     */
    template <typename dataType>
    void MiniDB<dataType>::toStream(std::ostream& sout){
      std::size_t count{1}; //user based indexing to show the list items
      cp = db_store.begin(); //Changing the cp to point at the beginning
      while (cp != db_store.end()){ //Loop through until cp points to the end of the db
        sout << count << ". " << *cp << endl;
        cp++; //Incrementing cp
        count++; //Increment user based index
      }
      this->moveToLast(); //While loop breaks when cp points to the end of the db. Changing it to point to the last element.
    }

    //Output stream << operator overload
    template <typename dataType>
    std::ostream& operator<<(std::ostream& sout, MiniDB<dataType>& m_db){
      m_db.toStream(sout);
      return sout;
    }

#endif //A3_40014877_MINIDB_H
