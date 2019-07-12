#include<iostream>
#include"stack.h"

using namespace std;

Stack::Stack(int size) {
  this->size = size;
  top = -1;
  data = new int[size];
}

Stack::~Stack() {
  delete []data;
}

int Stack::push(int item) {
  if(top < size - 1) {
    data[++top] = item;
  } else {
    throw "Stack overflow";
  }
}

int Stack::pop() {
  if(top >= 0) {
    return data[top--];
  }
  throw "Stack underflow";
}

int Stack::peek(int index) {
  if(index - 1 <= top) {
    return data[top - (index - 1)];
  }
  throw "Invalid index";
}

int Stack::stackTop() {
  if(top > -1) {
    return data[top];
  }
  throw "Stack is empty";
}

bool Stack::isEmpty() {
  return top == -1;
}

bool Stack::isFull() {
  return top == (size - 1);
}

void Stack::display() {
  for(int i = top; i >= 0; i--) {
    cout<<data[i]<<endl;
  }
}
