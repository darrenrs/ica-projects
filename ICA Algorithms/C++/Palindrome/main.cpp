#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include <cmath>

using namespace std;

int main() {
  int base_number = 0;
  int square_number = 0;
  bool is_found = false;

  do {
    base_number++;
    square_number = pow(base_number, 2);
    
    cout << "Checking " << base_number << " (squared " << square_number << ") ..." << endl;

    if (square_number >= 1e+5) {
      string number_string = to_string(square_number);
      string final_string = to_string(square_number);

      reverse(final_string.begin(), final_string.end());

      if (number_string == final_string) {
        is_found = true;
        cout << "Correct number!" << endl;
      } else {
        cout << "Squared number is not a palindrome" << endl;
      }
    } else {
      cout << "Squared number is below 100,000" << endl;
    }

    cout << endl;

  } while (!is_found);

  return square_number;
}