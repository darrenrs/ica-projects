#include <iostream>
#include <cmath>

using namespace std;

double paymentCalculator(double p, double r, double n) {
  return (p * r) / (1 - pow(1 + r, -n));
}

int main() {
  double p;
  double r;
  double n;

  cout << "What is the principal?"
       << endl
       << " > ";

  cin >> p;

  cout << endl 
       << "What is the interest rate in decimal form?"
       << endl
       << " > ";

  cin >> r;

  cout << endl 
       << "How many years are there?"
       << endl
       << " > ";

  cin >> n;

  cout << endl
       << "The payment is "
       << paymentCalculator(p, r, n * 12)
       << "."
       << endl;
}