#include<iostream>

using namespace std;

struct TreeNode {
  struct TreeNode *left;
  struct TreeNode *right;
  int data;
};

struct Node {
  struct TreeNode *data;
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
    void enqueue(struct TreeNode * item);
    struct TreeNode * dequeue();
    void display();
    bool isEmpty();
};
