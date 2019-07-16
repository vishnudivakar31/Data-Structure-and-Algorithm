#include<iostream>
#include"queue.h"

using namespace std;

class Tree {
  private:
    struct TreeNode *root;
    int length;
  public:
    Tree();
    ~Tree();
    void append(int data);
    void display();
};
