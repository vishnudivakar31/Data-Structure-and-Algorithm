#include<iostream>
#include"priority_queue.h"

using namespace std;

PriorityQueue::PriorityQueue(int priorities) {
  this->priorities = priorities;
  queues = new Queue[priorities];
}

PriorityQueue::~PriorityQueue() {
  delete []queues;
}
void PriorityQueue::enqueue(int item, int priority) {
  queues[priority - 1].enqueue(item);
}
int PriorityQueue::dequeue() {
  int result;
  for(int i = 0; i < priorities; i++) {
    if(!queues[i].isEmpty()) {
      result = queues[i].dequeue();
      return result;
    }
  }
  throw "queue underflow";
}
void PriorityQueue::display() {
  for(int i = 0; i < priorities; i++) {
    if(!queues[i].isEmpty()) {
      queues[i].display();
    }
  }
}
