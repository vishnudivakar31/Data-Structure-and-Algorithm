#include<iostream>
#include"TreeNode.h"
#include"Node.h"

using namespace std;

class Stack {
  private:
    struct Node *top;
    int size;
  public:
    Stack();
    ~Stack();
    void push(struct TreeNode *item);
    struct TreeNode * pop();
    struct TreeNode * peek(int index);
    struct TreeNode * stackTop();
    bool isEmpty();
    void display();
};
