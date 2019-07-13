#include<iostream>
#include"stack.h"
#include"postfix.h"

using namespace std;

int main() {
  char rawFormula[50];
  cout<<"Enter the formula: ";
  cin>>rawFormula;
  Postfix postfix(rawFormula, 50);
  try {
    cout<<"Postfix Formula: "<<postfix.convert()<<endl;
    cout<<"Value is "<<postfix.evaluate()<<endl;
  } catch(const char *err) {
    cerr<<err<<endl;
  }
  return 0;
}
