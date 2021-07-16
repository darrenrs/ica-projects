#include <iostream>
#include <string>

using namespace std;

string first_string;

int main() {
  cout << "What is the best?\n> ";
  getline(cin, first_string);
  cout << endl << first_string << " is the best!" << endl;
}