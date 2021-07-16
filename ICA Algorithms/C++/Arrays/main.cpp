#include <iostream>
#include "stack.h"

using namespace std;

int main() {
  Stack main_stack = stack();

  for (int i = 0; i < 50; i++) {
    push(&main_stack, i);
  }

  cout << peek(&main_stack) << endl;
  
  return 0;
}