#include<iostream>
#include"stack.h"

using namespace std;

int main() {
  Stack stack;
  int choice, item, temp;
  do {
      cout<<"1.Add item"<<endl;
      cout<<"2.Display"<<endl;
      cout<<"3.Pop item"<<endl;
      cout<<"4.Peek item"<<endl;
      cout<<"5.Show top item"<<endl;
      cout<<"6.Is stack empty?"<<endl;
      cout<<"7.Quit"<<endl;
      cout<<"Enter your choice: ";
      cin>>choice;
      try {
        switch(choice) {
          case 1: cout<<"Enter item: ";
                  cin>>item;
                  stack.push(item);
                  break;
          case 2: stack.display();
                  break;
          case 3: temp = stack.pop();
                  cout<<"Popped element is "<<temp<<endl;
                  break;
          case 4: cout<<"Enter index: ";
                  cin>>item;
                  temp = stack.peek(item - 1);
                  cout<<"Element found at "<<item<<" is "<<temp<<endl;
                  break;
          case 5: temp = stack.stackTop();
                  cout<<"Element found at top is "<<temp<<endl;
                  break;
          case 6: if(stack.isEmpty()) {
                    cout<<"Stack is empty"<<endl;
                  } else {
                    cout<<"Stack is not empty"<<endl;
                  }
                  break;
          case 7: cout<<"Quiting."<<endl;
                  break;
          default: cout<<"Invalid entry"<<endl;
        }
      } catch(const char *msg) {
        cerr<<msg<<endl;
      }
  } while(choice != 7);
  return 0;
}
