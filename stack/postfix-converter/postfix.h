#include<iostream>

using namespace std;

class Postfix {
  private:
    char *raw;
    char *postfixFormula;
    bool isOperand(char src);
    int getPrecedence(char item, bool isStackItem);
  public:
    Postfix(char *raw, int size);
    ~Postfix();
    char* convert();
    char* getFormula();
    char* getRaw();
    int evaluate();
};
