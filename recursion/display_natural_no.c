#include<stdio.h>

void reverse(int n) {
  if(n > 0) {
    printf("No: %d\n", n);
    reverse(n - 1);
  }
}

void natural(int n) {
  if(n > 0) {
    natural(n - 1);
    printf("No: %d\n", n);
  }
}

int main() {
  natural(5);
  printf("reverse\n");
  reverse(5);
}
