#include<iostream>
#include"queue.h"

using namespace std;

int menuDriver() {
  int choice;
  cout<<"1.Add item"<<endl;
  cout<<"2.Display"<<endl;
  cout<<"3.Remove item"<<endl;
  cout<<"4.Is queue empty?"<<endl;
  cout<<"5.Is queue full?"<<endl;
  cout<<"6.Show first element"<<endl;
  cout<<"7.Show second element"<<endl;
  cout<<"8.Quit"<<endl;
  cout<<"Enter your choice: ";
  cin>>choice;
  return choice;
}

void queueOps(Queue *queue, int choice) {
  int item;
  bool status;
  try {
    switch(choice) {
      case 1: cout<<"Enter item: ";
              cin>>item;
              queue->enqueue(item);
              break;
      case 2: queue->display();
              break;
      case 3: queue->dequeue();
              break;
      case 4: status = queue->isEmpty();
              if(status) {
                cout<<"Queue is empty"<<endl;
              } else {
                cout<<"Queue is not empty"<<endl;
              }
              break;
      case 5: status = queue->isFull();
              if(status) {
                cout<<"Queue is full"<<endl;
              } else {
                cout<<"Queue is not full"<<endl;
              }
              break;
      case 6: cout<<"First element is "<<queue->findFirst()<<endl;
              break;
      case 7: cout<<"Last element is "<<queue->findLast()<<endl;
              break;
      case 8: cout<<"Quiting."<<endl;
              break;
      default: cout<<"Invalid choice"<<endl;
    }
  } catch(const char *msg) {
    cerr<<msg<<endl;
  }
}

int main() {
  int size, choice;

  cout<<"Enter the size of queue: ";
  cin>>size;

  Queue queue(size);

  do {
    choice = menuDriver();
    queueOps(&queue, choice);
  } while(choice != 8);

  return 0;
}
