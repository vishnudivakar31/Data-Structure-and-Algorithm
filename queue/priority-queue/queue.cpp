#include<iostream>
#include"queue.h"

using namespace std;

Queue::Queue() {
  front = NULL;
  rear = NULL;
  length = 0;
}

Queue::~Queue() {
  struct Node *currNode = front, *prevNode = NULL;
  while(currNode != NULL) {
    prevNode = currNode;
    currNode = currNode->next;
    delete prevNode;
  }
}

void Queue::enqueue(int item) {
  struct Node *newNode = new Node;
  newNode->data = item;
  newNode->next = NULL;
  length++;
  if(front == NULL) {
    front = newNode;
    rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int Queue::dequeue() {
  if(front != NULL) {
    int result = front->data;
    struct Node *tempNode = front;
    front = front->next;
    length--;
    delete tempNode;
    return result;
  }
  throw "queue is underflow.";
}

void Queue::display() {
  struct Node *currNode = front;
  while(currNode != NULL) {
    cout<<currNode->data<<endl;
    currNode = currNode->next;
  }
}

bool Queue::isEmpty() {
  return front == NULL;
}
