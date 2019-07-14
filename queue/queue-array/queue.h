#include<iostream>

using namespace std;

class Queue {
  private:
    int size;
    int length;
    int rear;
    int *data;
  public:
    Queue(int size);
    ~Queue();
    void enqueue(int item);
    int dequeue();
    bool isEmpty();
    bool isFull();
    int findFirst();
    int findLast();
    void display();
};
