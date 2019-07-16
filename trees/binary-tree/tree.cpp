#include<iostream>
#include"tree.h"

using namespace std;

Tree::Tree() {
  root = NULL;
  length = 0;
}
Tree::~Tree() {
  Queue queue;
  struct TreeNode *currNode = root;
  if(currNode) {
    queue.enqueue(currNode);
  }
  while(!queue.isEmpty()) {
    if(currNode->left) {
      queue.enqueue(currNode->left);
    }
    if(currNode->right) {
      queue.enqueue(currNode->right);
    }
    delete currNode;
    currNode = queue.dequeue();
  }
};
void Tree::append(int data) {
  struct TreeNode *newNode = new TreeNode;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  length++;
  if(root == NULL) {
    root = newNode;
  } else {
    Queue queue;
    struct TreeNode *currNode = root;
    while(currNode) {
      if(currNode->left == NULL) {
        currNode->left = newNode;
        break;
      } else if(currNode->right == NULL) {
        currNode->right = newNode;
        break;
      }
      queue.enqueue(currNode->left);
      queue.enqueue(currNode->right);
      currNode = queue.isEmpty() ? NULL : queue.dequeue();
    }
  }
}
 void Tree::display() {
   Queue queue;
   struct TreeNode *currNode = root;
   while(currNode) {
     cout<<currNode->data<<endl;
     if(currNode->left) {
       queue.enqueue(currNode->left);
     }
     if(currNode->right) {
       queue.enqueue(currNode->right);
     }
     currNode = queue.isEmpty() ? NULL : queue.dequeue();
   }
 }
