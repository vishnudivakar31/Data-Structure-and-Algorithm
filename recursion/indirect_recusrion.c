#include<stdio.h>

void funA(int n);
void funB(int n);

int main(int argc, char const *argv[]) {
  funA(20);
  return 0;
}

void funA(int n) {
  if(n > 0) {
    printf("Fun A: %d\n", n);
    funB(n - 1);
  }
}

void funB(int n) {
  if(n > 1) {
    printf("Fun B: %d\n", n);
    funA(n / 2);
  }
}
