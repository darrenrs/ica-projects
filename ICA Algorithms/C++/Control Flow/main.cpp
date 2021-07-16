#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <ctype.h>
#include <cmath>

using namespace std;

string functions[5] = {"Exit Program", "Letter Value", "Scrabble Value", "Caesar Cipher", "For Loop Assignment"};

void letterValue() {
  char letters[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
  string letter;
  char firstLetter;
  int letterFound = 0;

  cout << endl
       << "Please enter a letter."
       << endl
       << " > ";

  getline(cin, letter);
  
  firstLetter = letter[0];

  for (int i = 0; i < *(&letters + 1) - letters; i++) {
    if (letters[i] == toupper(firstLetter)) {
      cout << endl
           << "Letter Index: "
           << i + 1
           << endl;
      letterFound = 1;
      break;
    }
  }

  if (!letterFound) {
    cout << "Invalid character or not a single letter.";
  }
}

void scrabbleValue() {
  char letters[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
  int values[26] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
  string word;
  int currentValue = 0;

  cout << endl
    << "Please enter a word."
    << endl
    << " > ";

  getline(cin, word);

  for (int i = 0; i < word.size(); i++) {
    char thisLetter = toupper(word[i]);
    for (int j = 0; j < *(&letters + 1) - letters; j++) {
      if (letters[j] == thisLetter) {
        currentValue += values[j];
        break;
      }
    }
  }

  cout << endl
       << "Scrabble Value: "
       << currentValue
       << endl;
}

void caesarCipher() {
  char letters[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
  string word;
  string selectedIndexStr;
  int selectedIndex;
  string stringMod = "";

  cout << endl
    << "Please enter a word or phrase."
    << endl
    << " > ";

  getline(cin, word);

  cout << endl
    << "Please enter an index."
    << endl
    << " > ";

  getline(cin, selectedIndexStr);

  selectedIndex = stoi(selectedIndexStr);

  for (int i = 0; i < word.size(); i++) {
    char thisLetter = toupper(word[i]);
    for (int j = 0; j < *(&letters + 1) - letters; j++) {
      if (letters[j] == thisLetter) {
        char appendChar = letters[abs((j + selectedIndex)  % 25)];
        stringMod += appendChar;
        break;
      } else if (j == 25) {
        stringMod += thisLetter;
        break;
      }
    }
  }

  cout << endl
    << "Caesar Ciphered: "
    << stringMod
    << endl;
}

void forLoopMod10() {
  cout << endl;

  for (int i = 0; i <= 100; i++) {
    if (i % 10 == 0) {
      continue;
    }

    cout << i
         << endl;
  }
}

int functionSelection() {
  string selectedFunction;

  cout << "What option would you like to choose?"
    << endl;

  for (int i = 0; i < *(&functions + 1) - functions; i++) {
    cout << "[" + to_string(i) + "] " + functions[i]
         << endl;
  }
  cout << " > ";

  getline(cin, selectedFunction);

  return stoi(selectedFunction);
}

void functionManager(int option) {
  switch (option) {
    case 1:
      letterValue();
      cout << endl;
      break;
    case 2:
      scrabbleValue();
      cout << endl;
      break;
    case 3:
      caesarCipher();
      cout << endl;
      break;
    case 4:
      forLoopMod10();
      cout << endl;
      break;
    case 0:
      exit(0);
      break;
    default:
      cout << endl
           << "Invalid value."
           << endl;
      break;
  }
}

int main() {
  while (true) {
    int option = functionSelection();
    functionManager(option);
  }
}