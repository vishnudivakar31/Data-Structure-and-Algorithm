#include<iostream>
#include"queue.h"

using namespace std;

Queue::Queue(int size) {
  data = new int[size];
  this->size = size;
  rear = -1;
  length = 0;
}

Queue::~Queue() {
  delete []data;
}

void Queue::enqueue(int item) {
  if(length < size) {
    data[++rear] = item;
    length++;
  } else {
    throw "queue overflow!!!";
  }
}

int Queue::dequeue() {
  int elem;
  if(length > 0) {
    elem = data[0];
    for(int i = 0; i < length - 1; i++) {
      data[i] = data[i + 1];
    }
    length--;
    rear--;
    return elem;
  }
  throw "queue underflow!!!";
}

bool Queue::isEmpty() {
    return length == 0;
}

bool Queue::isFull() {
  return length == size;
}

int Queue::findFirst() {
  if(length > 0) {
    return data[0];
  }
  throw "queue is empty!!!";
}

int Queue::findLast() {
  if(length > 0) {
    return data[rear];
  }
  throw "queue is empty!!!";
}

void Queue::display() {
  cout<<"***QUEUE***"<<endl;
  for(int i = 0; i < length; i++) {
    cout<<data[i]<<endl;
  }
  cout<<"***********"<<endl;
}
