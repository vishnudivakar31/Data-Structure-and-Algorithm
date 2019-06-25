#include<stdio.h>
#include<stdlib.h>

struct Rectangle {
  int length;
  int breadth;
};

int area(struct Rectangle r) {
  return r.length * r.breadth;
}

int main() {
  struct Rectangle *p;
  p = (struct Rectangle *) malloc(sizeof(struct Rectangle));
  printf("Rectangle Area Finder\n");
  printf("Enter the length:");
  scanf("%d", &p->length);
  printf("Enter the breadth:");
  scanf("%d", &p->breadth);
  printf("Area of Rectangle: %d\n", area(*p));
  free(p);
  return 0;
}
