#include<stdio.h>

void TOH(int n, int a, int b, int c) {
  if(n > 0) {
    TOH(n - 1, a, c, b);
    printf("Moving %d to %d\n", a, c);
    TOH(n - 1, b, a, c);
  }
}

int main() {
  TOH(2, 1, 2, 3);
  return 0;
}
