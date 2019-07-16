#include<iostream>
#include"TreeNode.h"
#include"Node.h"

using namespace std;

class Queue {
  private:
    struct Node *front;
    struct Node *rear;
    int length;
  public:
    Queue();
    ~Queue();
    void enqueue(struct TreeNode * item);
    struct TreeNode * dequeue();
    void display();
    bool isEmpty();
};
