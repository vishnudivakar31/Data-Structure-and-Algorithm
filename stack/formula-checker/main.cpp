#include<iostream>
#include"stack.h"

#define FORMULA_ERRMSG "Formula is not complete";

using namespace std;

int main() {
  char formula[50];
  Stack stack;

  cout<<"Enter the formula: ";
  cin>>formula;
  try {
    for(int i = 0; formula[i] != '\0'; i++) {
      if(formula[i] == '{' || formula[i] == '(' || formula[i] == '[') {
        stack.push(formula[i]);
      } else if(formula[i] == '}' && stack.stackTop() == '{') {
        stack.pop();
      } else if(formula[i] == ')' && stack.stackTop() == '(') {
        stack.pop();
      } else if(formula[i] == ']' && stack.stackTop() == '[') {
        stack.pop();
      }
    }
    if(stack.isEmpty()) {
      cout<<"Formula is complete."<<endl;
    } else {
      throw FORMULA_ERRMSG;
    }
  } catch(const char *e) {
    cerr<<FORMULA_ERRMSG;
    cerr<<endl;
  }
  return 0;
}
