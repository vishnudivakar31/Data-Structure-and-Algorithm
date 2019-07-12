#include<iostream>
#include"stack.h"

using namespace std;

Stack::Stack() {
  top = NULL;
  size = 0;
}

Stack::~Stack() {
  struct Node *prev = NULL;
  while(top != NULL) {
    prev = top;
    top = top->next;
    delete prev;
  }
}

void Stack::push(int item) {
  struct Node *newNode = new Node;
  newNode->data = item;
  newNode->next = top;
  top = newNode;
  size++;
}

int Stack::pop() {
  struct Node *temp = top;
  int result;
  if(top != NULL) {
    result = top->data;
    top = top->next;
    delete temp;
    size--;
    return result;
  } else {
    throw "Stack underflow.";
  }
}

int Stack::peek(int index) {
  struct Node *currNode = top;
  for(int i = 0; i < index && currNode != NULL; i++) {
    currNode = currNode->next;
  }
  if(currNode != NULL) {
    return currNode->data;
  }
  throw "Invalid index";
}

int Stack::stackTop() {
  if(top != NULL) {
    return top->data;
  }
  throw "Stack is empty";
}

bool Stack::isEmpty() {
  return top == NULL;
}

void Stack::display() {
  struct Node *currNode = top;
  while(currNode != NULL) {
    cout<<currNode->data<<endl;
    currNode = currNode->next;
  }
}
