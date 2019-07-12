#include<iostream>

using namespace std;

class Stack {
  private:
    int *data;
    int size;
    int top;
  public:
    Stack(int size);
    ~Stack();
    int push(int item);
    int pop();
    int peek(int index);
    int stackTop();
    bool isEmpty();
    bool isFull();
    void display();
};
