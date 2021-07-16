#include <iostream>
#include <cmath>

using namespace std;

double hypotenuse(double a, double b) {
  return sqrt(pow(a, 2) + pow(b, 2));
}

int main() {
  double a;
  double b;

  cout << "What is the length of side a?"
       << endl
       << " > ";

  cin >> a;

  cout << endl 
       << "What is the length of side b?"
       << endl
       << " > ";

  cin >> b;

  cout << endl
       << "The length of the hypotenuse is "
       << hypotenuse(a, b)
       << "."
       << endl;
}