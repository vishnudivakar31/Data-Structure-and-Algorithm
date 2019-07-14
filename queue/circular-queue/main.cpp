#include<iostream>
#include"queue.h"

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

void queueOps(Queue *q, int choice) {
  int item;
  try {
    switch(choice) {
      case 1: cout<<"Enter item: ";
              cin>>item;
              q->enqueue(item);
              break;
      case 2: q->dequeue();
              break;
      case 3: q->display();
              break;
      case 4: cout<<"Quiting."<<endl;
              break;
      default: cout<<"Invalid choice"<<endl;
    }
  } catch(const char *msg) {
    cerr<<msg<<endl;
  }
}

int main() {
  int size, choice;

  cout<<"Enter the size: ";
  cin>>size;

  Queue queue(size);

  do {
    choice = menuDriver();
    queueOps(&queue, choice);
  } while(choice != 4);

  return 0;
}
