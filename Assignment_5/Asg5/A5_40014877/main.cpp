#include <iostream>
#include "Dog.h"
int main () {

  //2.6 sample run
  //Task 3
  //Using transform version since normal has been modified to sort by greater value
  DogMapDefault dogMap;
//  load_csvFile_for_transform(dogMap, "../dogDB.csv");
//  cout  <<  dogMap << endl;

  /*
   * Task 2
   * for each
   */

//  load_csvFile_for_each(dogMap, "../dogDB.csv");
//  cout  <<  dogMap << endl;

  /*
   * Task 4
   * Modifying the multimap to print the string in reverse order
   */

  std::multimap<std::string, Dog, std::greater<string>> dogMapReferse;
//  load_csvFile_Normal_Loop<std::greater<string>>(dogMapReferse, "../dogDB.csv");
//  cout << dogMapReferse << endl;

/*
 * task 5
 */
//  load_csvFile_for_transform(dogMap, "../dogDB2.csv");
//  DogMapDefault breedRangeMap1 = findBreedRange(dogMap, "Greyhound");
//  cout << breedRangeMap1 << endl;


//*************************************

/*
 * task 4
 */

test_is_palindrome();
cout << "\n";

/*
 * Task 5
 */
  std::vector<int> v1{ 1 }; // one element
   test_second_max(v1);
  std::vector<int> v2{ 1, 1 }; // all elements equal
   test_second_max(v2);
  std::vector<int> v3{ 1, 1, 3, 3, 7, 7 }; // at least with two distict elements
   test_second_max(v3);
  cout << "\n";


/*
 * Task 6
 */
  std::vector<std::string> vecstr
          { "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
            "range", "[first", "last)", "for", "which", "pred", "is", "true." };
  cout << testCountStringLambda(vecstr, 5) << endl;
  cout << testCountStringFreeFun(vecstr, 5) << endl;
  cout << testCountStringsFunctor(vecstr, 5) << endl;
  cout << "\n";

/*
 * Task 7
 */

  multisetUsingMyComparator<string>();
  
  return 0;
}
