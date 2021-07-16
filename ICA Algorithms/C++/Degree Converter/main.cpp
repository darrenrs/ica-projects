#include <iostream>
#include <string>

using namespace std;

string units[4] = {"Fahrenheit", "Celsius", "Rankine", "Kelvin"};

/* Converts all values to Kelvin (base unit) */
double convertToKelvin(int t, double v) {
  switch(t) {
    case 0:
      return double(v - 32) * ((double)5/(double)9) + 273.15;
    case 1:
      return v + 273.15;
    case 2:
      return v * ((double)5/(double)9);
    case 3:
      return v;
    default:
      return v;
  }
}

double convertFromKelvin(int t, double v) {
  switch(t) {
    case 0:
      return double(v - 273.15) * ((double)9/(double)5) + 32;
    case 1:
      return v - 273.15;
    case 2:
      return v * ((double)9/(double)5);
    case 3:
      return v;
    default:
      return v;
  }
}

/* Main routine */
int main() {
  int input;
  int output;

  cout << "Please specify your input unit!"
       << endl;
  
  for (int i = 0; i < *(&units + 1) - units; i++) {
    cout << "["+to_string(i)+"] "+units[i]
         << endl;
  }
  cout << " > ";

  cin >> input;

  cout << endl
       << "Please specify your output unit!"
       << endl;
  
  for (int i = 0; i < *(&units + 1) - units; i++) {
    cout << "["+to_string(i)+"] "+units[i]
         << endl;
  }
  cout << " > ";

  cin >> output;

  if (input <= 3 && input >= 0 && output <= 3 && output >= 0) {
    double inputValue;
    cout << endl
         << "How many degrees "+units[input]+" are you starting with?"
         << endl
         << " > ";
    
    cin >> inputValue;

    double kelvinValue = convertToKelvin(input, inputValue);

    double finalValue = convertFromKelvin(output, kelvinValue);

    cout << endl;
    cout << "This is equivalent to "+to_string(finalValue)+" degrees "+units[output]+"."
         << endl;
  } else {
    cout << endl
         << "Invalid requested operator."
         << endl;
  }
}