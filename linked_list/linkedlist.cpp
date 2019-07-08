#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

class LinkedList {
  private:
    struct Node *head;
    struct Node *tail;
    int length;
  public:
    LinkedList();
    LinkedList(int data);
    ~LinkedList();
    void append(int data);
    void delNode(int index);
    void display();
    int getLength();
};

LinkedList::LinkedList() {
  tail = head = NULL;
  length = 0;
}

LinkedList::LinkedList(int data) {
  struct Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  head = newNode;
  tail = newNode;
  length++;
}

LinkedList::~LinkedList() {
  struct Node *tempNode = head;
  while(tempNode != NULL) {
    tempNode = head->next;
    delete head;
    head = tempNode;
  }
  delete tail;
}

void LinkedList::append(int data) {
  struct Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  length++;
  if(head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void LinkedList::delNode(int index) {
  struct Node *currNode = head, *prevNode = NULL;
  if(head != NULL && index >= 0 && index < length) {
    if(index == 0) {
      currNode = currNode->next;
      delete head;
      head = currNode;
    } else {
      for(int i = 1; i <= index; i++) {
        prevNode = currNode;
        currNode = currNode->next;
      }
      prevNode->next = currNode->next;
      delete currNode;
      if(index == length - 1) {
        tail = prevNode;
      }
    }
    length--;
  }
}

void LinkedList::display() {
  struct Node *currNode = head;
  while(currNode != NULL) {
    cout<<currNode->data<<endl;
    currNode = currNode->next;
  }
}

int LinkedList::getLength() {
  return length;
}

int main() {
  LinkedList ll;
  int choice = 0, data = 0;
  do {
    cout<<"Menu\n";
    cout<<"1. Add Item\n";
    cout<<"2. Display Items\n";
    cout<<"3. Delete item\n";
    cout<<"4. Clear Screen\n";
    cout<<"5. Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch (choice) {
      case 1: cout<<"Enter your data: ";
              cin>>data;
              ll.append(data);
              break;
      case 2: ll.display();
              break;
      case 3: cout<<"Enter the index(0 - "<<ll.getLength() - 1<<") :";
              cin>>data;
              ll.delNode(data);
              break;
      case 4: system("clear");
              break;
      case 5: cout<<"Closing....\n";
              break;
      default: cout<<"Invalid entry.";
    }
  } while(choice != 5);
  return 0;
}
