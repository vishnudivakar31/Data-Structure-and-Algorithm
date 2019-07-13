#include<iostream>
#include<stdlib.h>
#include<math.h>
#include"postfix.h"
#include"stack.h"

using namespace std;

Postfix::Postfix(char *raw, int size) {
  this->raw = raw;
  postfixFormula = new char[size];
}

Postfix::~Postfix() {
  delete []postfixFormula;
}

int Postfix::getPrecedence(char item, bool isStackItem) {
  if(item == '+' || item == '-') {
    return isStackItem ? 2 : 1;
  } else if(item == '*' || item == '/') {
    return isStackItem ? 4 : 3;
  } else if(item == '^') {
    return isStackItem ? 5 : 6;
  } else if(item == '(') {
    return isStackItem ? 0 : 7;
  } else if(item == ')') {
    return 0;
  }
}

bool Postfix::isOperand(char src) {
  if (src != '+' && src != '-' && src != '*' && src != '/' && src != '(' && src !=')' && src != '^') {
    return true;
  }
  return false;
}

char* Postfix::convert() {
  int j = 0;
  Stack stack;
  for(int i = 0; raw[i] != '\0'; i++) {
    if(isOperand(raw[i])) {
      postfixFormula[j++] = raw[i];
    } else {
      while(!stack.isEmpty() && getPrecedence(raw[i], false) <= getPrecedence(stack.stackTop(), true)) {
        if(getPrecedence(raw[i], false) == getPrecedence(stack.stackTop(), true)) {
          stack.pop();
          break;
        } else {
          postfixFormula[j++] = stack.pop();
        }
      }
      if(getPrecedence(raw[i], false) != 0) {
        stack.push(raw[i]);
      }
    }
  }
  while(!stack.isEmpty()) {
    postfixFormula[j++] = stack.pop();
  }
  postfixFormula[j] = '\0';
  return postfixFormula;
}

char* Postfix::getFormula() {
  return postfixFormula;
}

char* Postfix::getRaw() {
  return raw;
}

int Postfix::evaluate() {
  int firstOperand, secondOperand;
  Stack stack;
  for(int i = 0; postfixFormula[i] != '\0'; i++) {
    if(isOperand(postfixFormula[i])) {
      stack.push(postfixFormula[i] - '0');
    } else {
      secondOperand = stack.pop();
      firstOperand = stack.pop();
      switch(postfixFormula[i]) {
        case '+': firstOperand += secondOperand;
                  break;
        case '-': firstOperand -= secondOperand;
                  break;
        case '*': firstOperand *= secondOperand;
                  break;
        case '/': firstOperand /= secondOperand;
                  break;
        case '^': firstOperand = pow(firstOperand, secondOperand);
                  break;
      }
      stack.push(firstOperand);
    }
  }
  return stack.pop();
}
