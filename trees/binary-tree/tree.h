#include<iostream>
#include"TreeNode.h"

using namespace std;

class Tree {
  private:
    struct TreeNode *root;
    int length;
    void preorder_recur(struct TreeNode *node);
    void inorder_recur(struct TreeNode *node);
  public:
    Tree();
    ~Tree();
    void append(int data);
    void display();
    void display_preorder_recur();
    void display_inorder_recur();
    void display_pre_order();
};
