#include<iostream>
#include<math.h>

using namespace std;

struct Node {
  int power;
  int coef;
  struct Node *next;
};

class Polynomial {
  private:
    int length;
    struct Node *eq;
    struct Node *lastItem;
  public:
    Polynomial(int length);
    ~Polynomial();
    void set(int power, int coef);
    int equate(int x);
    void display();
};

Polynomial::Polynomial(int length) {
  this->length = length;
  eq = NULL;
  lastItem = NULL;
}

Polynomial::~Polynomial() {
  struct Node *currNode = eq, *prev = NULL;
  while(currNode != NULL) {
    prev = currNode;
    currNode = currNode->next;
    delete prev;
  }
}

void Polynomial::set(int power, int coef) {
  struct Node *newNode = new Node;
  newNode->power = power;
  newNode->coef = coef;
  newNode->next = NULL;
  if(eq == NULL) {
    eq = newNode;
    lastItem = newNode;
  } else {
    lastItem->next = newNode;
    lastItem = newNode;
  }
}

int Polynomial::equate(int x) {
  int result = 0;
  struct Node *currNode = eq;
  while(currNode != NULL) {
    result += (currNode->coef) * pow(x, currNode->power);
    currNode = currNode->next;
  }
  return result;
}

void Polynomial::display() {
  struct Node *currNode = eq;
  while(currNode->next != NULL) {
    cout<<currNode->coef<<"x^"<<currNode->power<<" + ";
    currNode = currNode->next;
  }
  cout<<currNode->coef<<"x^"<<currNode->power<<endl;
}

int main() {
    int length, power, coef;
    cout<<"Enter the length: ";
    cin>>length;
    Polynomial poly(length);
    for(int i = 0; i < length; i++) {
      cout<<"Term "<<i + 1<<", Power: ";
      cin>>power;
      cout<<"Term "<<i + 1<<", Coef: ";
      cin>>coef;
      poly.set(power, coef);
    }
    cout<<"Value of Polynomial(x = 5): "<<poly.equate(5)<<endl;
    poly.display();
}
