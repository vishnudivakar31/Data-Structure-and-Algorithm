#include<stdio.h>

int combinationPascalTower(int n, int r) {
  if(r == 0 || n == r) {
    return 1;
  }
  return combinationPascalTower(n - 1, r - 1) + combinationPascalTower(n - 1, r);
}

int fact(int n) {
  if(n == 0) {
    return 1;
  }
  return fact(n - 1) * n;
}

int combinationFormula(int n, int r) {
  int num = 0, rFact = 0, deno = 0;
  num = fact(n);
  rFact = fact(r);
  deno = fact(n - r);
  return num / (rFact * deno);
}

int main(int argc, char const *argv[]) {
  int n = 0, r = 0;

  printf("Enter value for n:\n");
  scanf("%d", &n);

  printf("Enter value for r:\n");
  scanf("%d", &r);

  if(r > n) {
    printf("Invalid Enteries.\n");
    return -1;
  }

  /* Combination using Formula */
  printf("Combination using formula: %d.\n", combinationFormula(n, r));
  /****************************/

  /* Combination using Pascal's Tower */
  printf("Combination using Pascal's Tower: %d.\n", combinationPascalTower(n, r));
  /****************************/

  return 0;
}
