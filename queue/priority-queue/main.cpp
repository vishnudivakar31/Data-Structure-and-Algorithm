#include<iostream>
#include"priority_queue.h"

using namespace std;

int menuDriver() {
  int choice;
  cout<<"1.Add item"<<endl;
  cout<<"2.Remove item"<<endl;
  cout<<"3.Display"<<endl;
  cout<<"4.Quit"<<endl;
  cout<<"Enter your choice: ";
  cin>>choice;
  return choice;
}

void queueOps(PriorityQueue *q, int choice) {
  int item, priority;
  try {
    switch(choice) {
      case 1: cout<<"Enter item: ";
              cin>>item;
              cout<<"Enter priority: ";
              cin>>priority;
              q->enqueue(item, priority);
              break;
      case 2: q->dequeue();
              break;
      case 3: q->display();
              break;
      case 4: cout<<"Quiting"<<endl;
              break;
      default: cout<<"Invalid entry"<<endl;
    }
  } catch(const char *msg) {
    cerr<<msg<<endl;
  }
}

int main() {
  int choice;
  cout<<"Enter the no of priorties: ";
  cin>>choice;
  PriorityQueue queue(choice);
  do {
    choice = menuDriver();
    queueOps(&queue, choice);
  } while(choice != 4);
  return 0;
}
