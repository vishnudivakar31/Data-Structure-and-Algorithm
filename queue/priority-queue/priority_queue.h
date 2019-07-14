#include<iostream>
#include"queue.h"

class PriorityQueue {
  private:
    int priorities;
    Queue *queues;
  public:
    PriorityQueue(int priorities);
    ~PriorityQueue();
    void enqueue(int item, int priority);
    int dequeue();
    void display();
};
