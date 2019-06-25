#include<stdio.h>
#include<stdlib.h>

struct Rectangle {
  int length;
  int breadth;
};

void initialize(struct Rectangle *r, int length, int breadth) {
  r->length = length;
  r->breadth = breadth;
}

int area(struct Rectangle r) {
  return r.length * r.breadth;
}

void changeLength(struct Rectangle *r, int newLength) {
  r->length = newLength;
}

void main() {
  struct Rectangle r;
  initialize(&r, 10, 20);
  printf("Area: %d", area(r));
  changeLength(&r, 20);
  printf("Changed Area: %d", area(r));
}
