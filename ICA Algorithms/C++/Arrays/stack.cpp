#include <iostream>
#include "stack.h"

using namespace std;

Stack stack() {
  Stack stack;
  stack.index = 0;
  return stack;
}

void push(Stack* stack, int data) {
  if (stack->index >= SIZE) {
    cerr << "insufficient space" << endl;
  } else {
    stack->arr[stack->index] = data;
  }
}

int pop(Stack* stack) {
  if (stack->index <= 0) {
    cerr << "insufficient index" << endl;
    return -1;
  } else {
    stack->index--;
    return stack->arr[stack->index];
  }
}

int alloc(Stack* stack) {
  return stack->index;
}

int peek(Stack* stack) {
  return stack->arr[stack->index];
}