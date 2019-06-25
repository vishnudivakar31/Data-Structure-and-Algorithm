#include<stdio.h>

int fact(int n) {
  if(n == 0) {
    return 1;
  }
  return fact(n - 1) * n;
}

int main(int argc, char const *argv[]) {
  printf("Factorial of 5 is %d\n", fact(5));
  return 0;
}
