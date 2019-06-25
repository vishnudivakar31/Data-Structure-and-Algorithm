#include<stdio.h>

int sum(int n) {
  if(n == 0) {
    return 0;
  } else {
    return sum(n - 1) + n;
  }
}

int main(int argc, char const *argv[]) {
  printf("Sum of N(5) is %d.\n", sum(5));
  return 0;
}
