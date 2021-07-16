#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  cout << "Corrupt the Declaration of Independence!" << endl;
  cout << "If you ever desired to add your own nonsense to a historical document, say no more!" << endl;
  cout << "Copyright (C) 2021 Darren R. Skidmore." << endl;

  cout << endl << "What would you like to add?" << endl << "> ";

  ofstream file("usa.txt", ios::app);

  string usa_new_line;
  getline(cin, usa_new_line);

  file << endl << endl << usa_new_line;
  file.close();

  cout << endl << "Good job, you corrupted the Declaration of Independence." << endl;
}