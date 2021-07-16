#include <iostream>
#include <cmath>

using namespace std;

int * pennySplicer(int pennies) {
  static int data[5];
  
  for (int i = 5; i >= 0; i--) {
    double divisor;

    if (i % 2 == 1) {
      divisor = pow(10, (i-1)/2);
    } else {
      divisor = pow(5, i/2);
    }

    data[(5-i)] = pennies / divisor;
    pennies -= data[(5-i)] * divisor;
  }

  return data;
}

int main() {
  int pennies;

  cout << endl
       << "How many pennies do you have?"
       << endl
       << " > ";

  cin >> pennies;

  int *data;

  data = pennySplicer(pennies);

  cout << endl
       << "You have "
       << to_string(data[0])
       << " dollar bills, "
       << to_string(data[1])
       << " quarters, "
       << to_string(data[2])
       << " dimes, "
       << to_string(data[3])
       << " nickels, and "
       << to_string(data[4])
       << " pennies."
       << endl;
}