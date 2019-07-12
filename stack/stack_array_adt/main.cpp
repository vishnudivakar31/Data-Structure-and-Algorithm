#include<iostream>
#include"stack.h"

using namespace std;

int main() {
  int choice, item, size;
  cout<<"Enter the stack size: ";
  cin>>size;
  Stack stack(size);
  do {
    cout<<"1.Add element"<<endl;
    cout<<"2.Display stack"<<endl;
    cout<<"3.Pop element"<<endl;
    cout<<"4.Peek element"<<endl;
    cout<<"5.Show stack top"<<endl;
    cout<<"6.Is empty?"<<endl;
    cout<<"7.Is Full?"<<endl;
    cout<<"8.Quit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    try {
      switch (choice) {
        case 1: cout<<"Enter element to push: ";
                cin>>item;
                stack.push(item);
                break;
        case 2: stack.display();
                break;
        case 3: cout<<"Pop element: "<<stack.pop()<<endl;
                break;
        case 4: cout<<"Enter the index: ";
                cin>>item;
                cout<<"Element found at "<<item<<" is "<<stack.peek(item)<<"."<<endl;
                break;
        case 5: cout<<"Top element is "<<stack.stackTop()<<"."<<endl;
                break;
        case 6: if(stack.isEmpty()) {
                  cout<<"Stack is empty."<<endl;
                } else {
                  cout<<"Stack is not empty."<<endl;
                }
                break;
        case 7: if(stack.isFull()) {
                  cout<<"Stack is full"<<endl;
                } else {
                  cout<<"Stack is not full"<<endl;
                }
                break;
        case 8: cout<<"Quiting."<<endl;
                break;
        default: cout<<"Invalid entry."<<endl;
      }
    } catch(const char *msg) {
      cerr<<msg<<endl;
    }
  } while(choice != 8);
  return 0;
}
