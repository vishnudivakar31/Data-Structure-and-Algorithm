#include<iostream>

using namespace std;

class Queue {
  private:
    int *data;
    int front;
    int rear;
    int size;
    int length;
    int next(int index);
  public:
    Queue(int size);
    ~Queue();
    void enqueue(int item);
    int dequeue();
    void display();
};
