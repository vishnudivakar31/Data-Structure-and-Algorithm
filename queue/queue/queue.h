#include<iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

class Queue {
  private:
    struct Node *front;
    struct Node *rear;
    int length;
  public:
    Queue();
    ~Queue();
    void enqueue(int item);
    int dequeue();
    void display();
};
