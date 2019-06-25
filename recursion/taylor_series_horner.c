#include<stdio.h>

int taylorIterative(int x, int n) {
  double result = 1.0;
  for(; n > 0; n--) {
    result = ((x / n) * result) + 1;
  }
  return result;
}

int taylorRecursion(int x, int n) {
  static int result = 1;
  if(n == 0) {
    return result;
  }
  result = ((x / n) * result) + 1;
  return taylorRecursion(x, n - 1);
}

int main() {
  printf("Taylor Series.\n");
  printf("Taylor series(Iterative) for 10 with 4 series is %d.\n", taylorIterative(10, 4));
  printf("Taylor series(Recursive) for 10 with 4 series is %d.\n", taylorRecursion(10, 4));
}
