#ifndef TreeNode_H
#define TreeNode_H
#include<iostream>

using namespace std;

struct TreeNode {
  struct TreeNode *left;
  struct TreeNode *right;
  int data;
};
#endif
