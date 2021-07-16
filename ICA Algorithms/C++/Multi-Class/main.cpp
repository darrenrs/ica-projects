#include <iostream>
#include <string>
#include "Star.h"

using namespace std;

int main() {
  // Automatic variables/objects
  cout << "----- ACTOR 1 -----" << endl;
  Person p1("Nathan Munn", "7 Adrian Avenue", "Ellington, CT");
  p1.display();
  cout << endl;

  cout << "----- ACTOR 2 -----" << endl;
  Actor p2("Tom Hanks", "Forrest Gump", "777 Richie Rich Lane", "Beverly Hills, CA");
  p2.display();
  cout << endl;

  cout << "----- ACTOR 3 AUTO -----" << endl;
  Star s("John Wayne", "Cranston Snort", 50000000, "123 Palm Springs", "Ogden, UT");
  
  s.setDate(1960, 12, 25);
  s.display();
  cout << endl;

  // Dynamic variable/object
  cout << "----- ACTOR 3 DYNAMIC -----" << endl;
  Star* s2 = new Star("John Wayne", "Cranston Snort", 50000000, "123 Palm Springs", "Ogden, UT");

  s2->setDate(1960, 12, 25);
  s2->display();
  cout << endl;

  return 0;
}