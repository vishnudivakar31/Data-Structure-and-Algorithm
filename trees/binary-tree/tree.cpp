#include<iostream>
#include"tree.h"
#include"queue.h"
#include"stack.h"

using namespace std;

Tree::Tree() {
  root = NULL;
  length = 0;
}
Tree::~Tree() {
  Queue queue;
  struct TreeNode *currNode = root;
  while(currNode) {
    if(currNode->left) {
      queue.enqueue(currNode->left);
    }
    if(currNode->right) {
      queue.enqueue(currNode->right);
    }
    delete currNode;
    currNode = queue.isEmpty() ? NULL : queue.dequeue();
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

void Tree::preorder_recur(struct TreeNode *node) {
  if(node != NULL) {
    cout<<node->data<<endl;
    preorder_recur(node->left);
    preorder_recur(node->right);
  }
}

void Tree::display_preorder_recur() {
 preorder_recur(root);
}

void Tree::inorder_recur(struct TreeNode *node) {
  if(node != NULL) {
    inorder_recur(node->left);
    cout<<node->data<<endl;
    inorder_recur(node->right);
  }
}

void Tree::display_inorder_recur() {
 inorder_recur(root);
}

void Tree::display_pre_order() {
  struct TreeNode *currNode = root;
  Stack stack;
  while (currNode != NULL || !stack.isEmpty()) {
    if(currNode != NULL) {
      cout<<currNode->data<<endl;
      stack.push(currNode);
      currNode = currNode->left;
    } else {
      currNode = stack.pop();
      currNode = currNode->right;
    }
  }
}

void Tree::display_in_order() {
  struct TreeNode *currNode = root;
  Stack stack;
  while(currNode != NULL || !stack.isEmpty()) {
    if(currNode != NULL) {
      stack.push(currNode);
      currNode = currNode->left;
    } else {
      currNode = stack.pop();
      cout<<currNode->data<<endl;
      currNode = currNode->right;
    }
  }
}

void Tree::display_level_order() {
  struct TreeNode *currNode = root;
  Queue queue;
  while(currNode != NULL) {
    if(currNode->left) {
      queue.enqueue(currNode->left);
    }
    if(currNode->right) {
      queue.enqueue(currNode->right);
    }
    cout<<currNode->data<<endl;
    currNode = queue.isEmpty() ? NULL : queue.dequeue();
  }
}

int Tree::countNodesRecur(struct TreeNode *node) {
  int x, y;
  if(node != NULL) {
    x = countNodesRecur(node->left);
    y = countNodesRecur(node->right);
    return x + y + 1;
  }
  return 0;
}

int Tree::countNodes() {
  return countNodesRecur(root);
}
