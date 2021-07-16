#pragma once
#define SIZE 50

struct Stack {
  int arr[SIZE];
  int index;
};

Stack stack();
void push(Stack* stack, int data);
int pop(Stack* stack);
int alloc(Stack* stack);
int peek(Stack* stack);