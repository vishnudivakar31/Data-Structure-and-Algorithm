#include<stdio.h>
#include<stdlib.h>

int *dynaArr;

int iterativeFib(int n) {
  int firstTerm = 0, secondTerm = 1, result = 0, i = 0;
  if(n <= 1) {
    result = n;
  }
  for(i = 2; i <= n; i++) {
    result = firstTerm + secondTerm;
    firstTerm = secondTerm;
    secondTerm = result;
  }
  return result;
}

int normalFibRecur(int n) {
  if(n <= 1) {
    return n;
  }
  return normalFibRecur(n - 2) + normalFibRecur(n - 1);
}

int memorFibRecur(int n) {
  if(n <= 1) {
    *(dynaArr + n) = n;
    return n;
  } else {
    if(*(dynaArr + (n - 2)) == -1) {
      *(dynaArr + (n - 2)) = memorFibRecur(n - 2);
    }
    if(*(dynaArr + (n - 1)) == -1) {
      *(dynaArr + (n - 1)) = memorFibRecur(n - 1);
    }
    return *(dynaArr + (n - 2)) + *(dynaArr + (n - 1));
  }
}

int main() {
  int terms = 0, i = 0;
  printf("Enter the number of terms:");
  scanf("%d", &terms);
  dynaArr = (int *) malloc(terms * sizeof(int));
  for(; i < terms; i++) {
    *(dynaArr + i) = -1;
  }

  /* Iterative Algo */
  printf("Iterative Algo\n");
  for(i = 0; i < terms; i++) {
    printf("%d\n", iterativeFib(i));
  }
  printf("\n");
  /******************/

  /* Recursive Algo */
  printf("Recursive Algo\n");
  for(i = 0; i < terms; i++) {
    printf("%d\n", normalFibRecur(i));
  }
  printf("\n");
  /******************/

  /* Memorative Recursive Algo */
  printf("Memorative Recursive Algo\n");
  for(i = 0; i < terms; i++) {
    printf("%d\n", memorFibRecur(i));
  }
  printf("\n");
  /******************/
}
