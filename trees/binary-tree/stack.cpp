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

void Stack::push(struct TreeNode *item) {
  struct Node *newNode = new Node;
  newNode->data = item;
  newNode->next = top;
  top = newNode;
  size++;
}

struct TreeNode * Stack::pop() {
  struct Node *temp = top;
  struct TreeNode * result;
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

struct TreeNode * Stack::peek(int index) {
  struct Node *currNode = top;
  for(int i = 0; i < index && currNode != NULL; i++) {
    currNode = currNode->next;
  }
  if(currNode != NULL) {
    return currNode->data;
  }
  throw "Invalid index";
}

struct TreeNode * Stack::stackTop() {
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
