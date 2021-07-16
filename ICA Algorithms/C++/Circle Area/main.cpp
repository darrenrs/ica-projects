#include <iostream>
#include <cmath>

using namespace std;

double circleArea(double radius) {
  return M_PI * pow(radius, 2);
}

int main() {
  double circleRadius;

  cout << "What is the radius of the circle?"
       << endl
       << " > ";

  cin >> circleRadius;

  cout << endl 
       << "The area of this circle is "
       << circleArea(circleRadius)
       << "."
       << endl;
}