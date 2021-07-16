//Copyright 2020, Bradley Peterson, Weber State University, All rights reserved. (Sep 2020)

#include <iostream>
#include <map>
#include <algorithm>
#include <list>
#include <sstream>
#include <memory>

template <typename T> class DoublyLinkedList;

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::stringstream;
using std::iter_swap;
using std::make_shared;
using std::shared_ptr;


//******************
//The Node class
//******************
template <typename T>
struct Node {
  T data{};
  shared_ptr<Node<T>> prev{ nullptr };
  shared_ptr<Node<T>> next{ nullptr };
};

//******************
//The Iterator class
//******************
template <typename T>
class Iterator {
  friend class DoublyLinkedList<T>;
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = T;
  using difference_type = int;
  using pointer = T*;
  using reference = T&;

  T& operator*() const;
  Iterator<T> operator++();
  Iterator<T> operator++(int);  //That int is a code saying it's postfix
  Iterator<T> operator--();
  bool operator!=(const Iterator<T>& rhs);
  bool operator==(const Iterator<T>& rhs);

private:
  shared_ptr<Node<T>> node {
    nullptr
  };

  bool pastTheEnd = false;
};

//***********************************
//The Iterator class methods
//***********************************

template <typename T>
T& Iterator<T>::operator*() const {
  return node->data;
}

template <typename T>
Iterator<T> Iterator<T>::operator++() {
  if (node->next == nullptr || Iterator<T>::pastTheEnd) {
    Iterator<T>::pastTheEnd = true;
  } else {
    Iterator<T>::node = node->next;
  }

  return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
  auto copyOfItself = *this;

  if (node->next == nullptr || Iterator<T>::pastTheEnd) {
    Iterator<T>::pastTheEnd = true;
  } else {
    Iterator<T>::node = node->next;
  }

  return copyOfItself;
}

template <typename T>
Iterator<T> Iterator<T>::operator--() {
  if (node->prev != nullptr && !pastTheEnd) {
    Iterator<T>::node = node->prev;
  }

  Iterator<T>::pastTheEnd = false;

  return *this;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& rhs) {
  if (this->pastTheEnd == rhs.pastTheEnd && this->node == rhs.node) {
    return false;
  } else {
    return true;
  }
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& rhs) {
  if (this->pastTheEnd == rhs.pastTheEnd && this->node == rhs.node) {
    return true;
  } else {
    return false;
  }
}


//****************************
//The DoublyLinkedList class
//****************************
template <typename T>
class DoublyLinkedList {

public:

  //public members of the DoublyLinkedList class
  DoublyLinkedList();
  ~DoublyLinkedList();
  string getStringFromList();

  void insertFirst(const T&);
  void insertLast(const T&);

  Iterator<T> begin();
  Iterator<T> end();

protected:
  shared_ptr<Node<T>> first{ nullptr };
  shared_ptr<Node<T>> last{ nullptr };
  unsigned int count;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
  count = 0;
  first = nullptr;
  last = nullptr;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  while (first != last) {
    first = first->next;
    first->prev.reset();
  }
}

template <typename T>
void DoublyLinkedList<T>::insertFirst(const T& item) {
  shared_ptr<Node<T>> temp = make_shared<Node<T>>();

  temp->data = item;
  if (!first) {
    // Scenario: List is empty
    last = temp;
  }
  else {
    first->prev = temp;
    temp->next = first;
  }
  first = temp;
}

template <typename T>
void DoublyLinkedList<T>::insertLast(const T& item) {
  shared_ptr<Node<T>> temp = make_shared<Node<T>>();

  temp->data = item;
  if (!first) {
    // Scenario: List is empty
    first = temp;
  }
  else {
    last->next = temp;
    temp->prev = last;
  }
  last = temp;
}

//This method helps return a string representation of all nodes in the linked list
template <typename T>
string DoublyLinkedList<T>::getStringFromList() {
  stringstream ss;
  if (!first) {
    ss << "The list is empty.";
  }
  else {

    shared_ptr<Node<T>> currentNode{ first };
    ss << currentNode->data;
    currentNode = currentNode->forward;

    while (currentNode != nullptr) {
      ss << " " << currentNode->data;
      currentNode = currentNode->forward;
    }
  }
  return ss.str();
}

//***********************************
//The DoublyLinkedList class methods
//***********************************
//TODO, implement the  the definitions for the begin() and end() methods.  They each return an Iterator<T> object

template <typename T>
Iterator<T> DoublyLinkedList<T>::begin() {
  Iterator<T> temp;

  if (first == nullptr) {
    temp.pastTheEnd = true;
  } else {
    temp.pastTheEnd = false;
  }

  temp.node = DoublyLinkedList<T>::first;

  return temp;
}

template <typename T>
Iterator<T> DoublyLinkedList<T>::end() {
  Iterator<T> temp;

  temp.pastTheEnd = true;

  temp.node = DoublyLinkedList<T>::last;

  return temp;
}

//***********************************
//TODO, complete the assignmentReverse function.
//Note that begin and end here are are iterators (The T is just saying it can be any kind of iterator).
//Our tools are ***ONLY***
//++, --, !=, *, ==
//For example, these three lines do a swap:
//auto temp = *end;
//*end = *begin;
//*begin = temp;

// Also: iter_swap(begin, end);  //Swaps the values pointed at by two iterators.  This sure comes in handy...
template <typename T>
void assignmentReverse(T begin, T end) {
  --end;

  while (begin != end) {
    iter_swap(begin, end);

    auto temp = end;

    ++begin;
    --end;

    if (begin == temp) {
      return;
    }
  } 
}



//----------------------------------------------------------------------------------------------------------------------------------------
//Copyright 2020, Bradley Peterson, Weber State University, All rights reserved. (Sep 2020)
//This helps with testing, do not modify.
bool checkTest(string testName, const string whatItShouldBe, const string whatItIs) {

  if (whatItShouldBe == whatItIs) {
    cout << "Passed " << testName << endl;
    return true;
  }
  else {
    cout << "****** Failed test " << testName << " ****** " << endl << "     Output was " << whatItIs << endl << "     Output should have been " << whatItShouldBe << endl;
    return false;
  }
}

template <typename T>
bool checkTest(string testName, const T whatItShouldBe, const T whatItIs) {

  if (whatItShouldBe == whatItIs) {
    cout << "Passed " << testName << endl;
    return true;
  }
  else {
    cout << "****** Failed test " << testName << " ****** " << endl << "     Output was " << whatItIs << endl << "     Output should have been " << whatItShouldBe << endl;
    return false;
  }
}


//This helps with testing, do not modify.
bool checkTestMemory(string testName, int whatItShouldBe, int whatItIs) {

  if (whatItShouldBe == whatItIs) {
    cout << "Passed " << testName << endl;
    return true;
  }
  else {
    cout << "***Failed test " << testName << " *** " << endl << "  There are " << whatItIs << " bytes of memory yet to be reclaimed!" << endl;
    return false;
  }
}


//This helps with testing, do not modify.
void testIteratorFundamentals() {
  DoublyLinkedList<int> d;

  //Our test data should have all even numbers from 2 to 20
  for (int i = 2; i <= 20; i += 2) {
    d.insertLast(i);
  }

  //Get an iterator which points at the beginning of the list
  Iterator<int> iter = d.begin();

  //Test the operator* operator
  checkTest("testIteratorFundamentals #1", 2, *iter);

  //Test the ++ prefix increment opreator
  ++iter;
  checkTest("testIteratorFundamentals #2", 4, *iter);

  //Test the != operator
  //reset them back to the start
  iter = d.begin();
  Iterator<int> anotherIter = d.begin();
  if (iter != anotherIter) {
   cout << "****** Failed testIteratorFundamentals #3 ****** " << endl << "     The two iteraters held the same data." << endl;
  } else {
   cout << "Passed testIteratorFundamentals #3" << endl;
  }

  //Again test the != operator
  ++iter;
  if (iter != anotherIter) {
   cout << "Passed testIteratorFundamentals #4" << endl;
  }
  else {
   cout << "****** Failed testIteratorFundamentals #4 ****** " << endl << "     The two iteraters held different data." << endl;
  }

  //Test the ++postfix increment
  iter = d.begin(); //reset it back to the start
  anotherIter = iter++;  //anotherIter should be at the data 2

  checkTest("testIteratorFundamentals #5", 4, *iter);
  checkTest("testIteratorFundamentals #6", 2, *anotherIter);

  // TODO:
  // We have !=, *, ++, and .begin() tested by this point.  Now test .end().  Do that with a for loop.  
  stringstream ss;
  cout << "testIteratorFundamentals test #7, this should display 2 4 6 8 10 12 14 16 18 20." << endl;
  for (auto item : d) {
   cout << item << " ";
   ss << item << " ";
  }
  cout << endl;


  checkTest("testIteratorFundamentals test #7", "2 4 6 8 10 12 14 16 18 20 ", ss.str());
  ss.str("");
}

//This helps with testing, do not modify.
void testIteratorIncrement() {
  DoublyLinkedList<int>* d = new DoublyLinkedList<int>;

  //Our test data should have all even numbers from 2 to 20
  for (int i = 2; i <= 20; i += 2) {
   d->insertLast(i);
  }

  //Get an iterator which points at the beginning of the list
  Iterator<int> iter = d->begin();

  //Test that it does point to the first
  checkTest("testIteratorsIncrement #1", 2, *iter);

  //Test that our Iterator can move forward;
  ++iter;
  checkTest("testIteratorsIncrement #2", 4, *iter);


  //Test that our Iterator can move forward again;
  ++iter;
  checkTest("testIteratorsIncrement #3", 6, *iter);

  //move it some more
  for (int i = 0; i < 6; i++) {
   ++iter;
  }
  checkTest("testIteratorsIncrement #4", 18, *iter);

  //Hit the end
  ++iter;
  checkTest("testIteratorsIncrement #5", 20, *iter);

  ////Verify we move the iterator past the end without crashing
  ++iter;
  string didntCrash = "did not crash";
  checkTest("testIteratorsIncrement #6", didntCrash, didntCrash);


  delete d;
}

//This helps with testing, do not modify.
void testIteratorDecrement() {
  DoublyLinkedList<int>* d = new DoublyLinkedList<int>;

  //Our test data should have all even numbers from 2 to 20
  for (int i = 2; i <= 20; i += 2) {
   d->insertLast(i);
  }

  //Get an Iterator which points at the end of the list    (Not on the last item, but on the "end")
  Iterator<int> iter = d->end();
  --iter;  //We have to do a decrement otherwise it crashes  (Yes, this is how the end iterator works)

  //Test that it does point to the first
  checkTest("testIteratorsDecrement #1", 20, *iter);

  //Test that our Iterator can move forward;
  --iter;
  checkTest("testIteratorsDecrement #2", 18, *iter);

  //move it some more
  for (int i = 0; i < 7; i++) {
   --iter;
  }
  checkTest("testIteratorsDecrement #3", 4, *iter);

  //Hit the end
  --iter;
  checkTest("testIteratorsDecrement #4", 2, *iter);

  //Now go back forward
  ++iter;
  checkTest("testIteratorsDecrement #5", 4, *iter);

  delete d;
}

//This helps with testing, do not modify.
void testIterationTricky() {
  DoublyLinkedList<int> myListOneNode;

  myListOneNode.insertLast(42);
  cout << "TestIterationTricky test #1, the next line should display 42" << endl;
  stringstream ss;
  //see if we can just iterator through one item.
  for (auto i : myListOneNode) {
   cout << i << " ";
   ss << i << " ";
  }
  cout << endl;
  checkTest("TestIterationTricky test #1", "42 ", ss.str());
  ss.str("");

  DoublyLinkedList<int> myListEmpty;
  cout << "TestIterationTricky test #2, the next line shouldn't display anything" << endl;
  //see if we can just iterator through one item.
  for (auto i : myListEmpty) {
   cout << i << " ";
   ss << i << " ";
  }
  cout << endl;
  checkTest("TestIterationTricky test #2", "", ss.str());
  ss.str("");
}



//This helps with testing, do not modify.
void testAlgorithms() {
  DoublyLinkedList<int> myList;

  //Our test data should have all even numbers from 2 to 20
  for (int i = 2; i <= 6; i += 2) {
   myList.insertLast(i);
  }
  myList.insertLast(100);
  for (int i = 8; i <= 12; i += 2) {
   myList.insertLast(i);
  }
  myList.insertLast(100);
  for (int i = 14; i <= 20; i += 2) {
   myList.insertLast(i);
  }
  stringstream ss;
  cout << "testAlgorithms test #1, this should display 2 4 6 100 8 10 12 100 14 16 18 20." << endl;
  for (auto i : myList) {
   cout << i << " ";
   ss << i << " ";
  }
  cout << endl;
  checkTest("testAlgorithms test #1", "2 4 6 100 8 10 12 100 14 16 18 20 ", ss.str());
  ss.str("");

  //Test the STL reverse algorithm on our iterator
  cout << "testAlgorithms test #2, this should display 20 18 16 14 100 12 10 8 100 6 4 2." << endl;
  std::reverse(myList.begin(), myList.end());
  for (auto i : myList) {
   cout << i << " ";
   ss << i << " ";
  }
  cout << endl;
  checkTest("testAlgorithms test #2", "20 18 16 14 100 12 10 8 100 6 4 2 ", ss.str());
  ss.str("");

  //Get it back in ascending order using the STL reverse algorithm
  cout << "testAlgorithms test #3, this should display 2 4 6 100 8 10 12 100 14 16 18 20." << endl;
  std::reverse(myList.begin(), myList.end());
  for (auto i : myList) {
   cout << i << " ";
   ss << i << " ";
  }
  cout << endl;
  checkTest("testAlgorithms test #3", "2 4 6 100 8 10 12 100 14 16 18 20 ", ss.str());
  ss.str("");

  // Try a custom assignmentReverse function

  cout << "testAlgorithms test #4, this should display 20 18 16 14 100 12 10 8 100 6 4 2." << endl;
  assignmentReverse(myList.begin(), myList.end());
  for (auto i : myList) {
  cout << i << " ";
   ss << i << " ";
  }
  cout << endl;
  checkTest("testAlgorithms test #4", "20 18 16 14 100 12 10 8 100 6 4 2 ", ss.str());
  ss.str("");

  //Get it back in ascending order using the STL reverse algorithm
  assignmentReverse(myList.begin(), myList.end());
  for (auto i : myList) {
   cout << i << " ";
   ss << i << " ";
  }
  cout << endl;

  checkTest("testAlgorithms test #5", "2 4 6 100 8 10 12 100 14 16 18 20 ", ss.str());
  ss.str("");

  // Test assignmentReverse on an STL container:


  list<int> stlList;

  //Our test data should have all even numbers from 2 to 20
  for (int i = 2; i <= 6; i += 2) {
   stlList.push_back(i);
  }
  stlList.push_back(100);
  for (int i = 8; i <= 12; i += 2) {
   stlList.push_back(i);
  }
  stlList.push_back(100);
  for (int i = 14; i <= 20; i += 2) {
   stlList.push_back(i);
  }
  for (auto i : stlList) {
   cout << i << " ";
   ss << i << " ";
  }
  cout << endl;
  checkTest("testAlgorithms test #6", "2 4 6 100 8 10 12 100 14 16 18 20 ", ss.str());
  ss.str("");

  // Try a custom assignmentReverse function

  assignmentReverse(stlList.begin(), stlList.end());
  for (auto i : stlList) {
   cout << i << " ";
   ss << i << " ";
  }
  cout << endl;
  checkTest("testAlgorithms test #7", "20 18 16 14 100 12 10 8 100 6 4 2 ", ss.str());
  ss.str("");


}


void pressAnyKeyToContinue() {
  cout << "Press enter to continue...";
  cin.get();
}

int main() {

  // cout << "This first test can run forever until you get operators *, != and ++ implemented." << endl;
  pressAnyKeyToContinue();

  testIteratorFundamentals();
  pressAnyKeyToContinue();

  testIteratorIncrement();
  pressAnyKeyToContinue();

  testIteratorDecrement();
  pressAnyKeyToContinue();

  testIterationTricky();
  pressAnyKeyToContinue();

  testAlgorithms();
  pressAnyKeyToContinue();

  return 0;
}