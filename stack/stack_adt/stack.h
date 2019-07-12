#include<iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

class Stack {
  private:
    struct Node *top;
    int size;
  public:
    Stack();
    ~Stack();
    void push(int item);
    int pop();
    int peek(int index);
    int stackTop();
    bool isEmpty();
    void display();
};
