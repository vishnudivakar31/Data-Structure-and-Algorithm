#include<iostream>
#include"queue.h"

using namespace std;

Queue::Queue(int size) {
  this->size = size;
  data = new int[size];
  length = 0;
  front = -1;
  rear = -1;
}

Queue::~Queue() {
  delete []data;
};

int Queue::next(int index) {
  return (index + 1) % size;
}

void Queue::enqueue(int item) {
  if(length < size) {
    rear = next(rear);
    data[rear] = item;
    length++;
  } else {
    throw "queue overflow";
  }
}

int Queue::dequeue() {
  if(length > 0) {
    front = next(front);
    int result = data[front];
    length--;
    return result;
  }
  throw "queue underflow";
}

void Queue::display() {
  int temp = front;
  for(int i = length; i > 0; i--) {
    temp = next(temp);
    cout<<data[temp]<<endl;
  }
}
