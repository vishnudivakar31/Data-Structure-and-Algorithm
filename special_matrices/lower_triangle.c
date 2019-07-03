#include<stdio.h>
#include<stdlib.h>

struct Matrix {
  int *m;
  int size;
};

int sumOfNaturalNo(int n) {
  return n * (n + 1) / 2;
}

struct Matrix * initialize(int size) {
  struct Matrix *matrix = (struct Matrix *) malloc(sizeof(struct Matrix));
  matrix->m = (int*) malloc(sumOfNaturalNo(size) * sizeof(int));
  matrix->size = size;
  return matrix;
}

void setItem(struct Matrix *matrix, int i, int j, int item) {
  if(i >= j) {
    matrix->m[(i * (i - 1) / 2) + j - 1] = item;
  }
}

int getItem(struct Matrix *matrix, int i, int j) {
  if(i >= j) {
    return matrix->m[(i * (i - 1) / 2) + j - 1];
  }
  return 0;
}

void display(struct Matrix *m) {
  int i, j;
  for(i = 1; i <= m->size; i++) {
    for(j = 1; j <= m -> size; j++) {
      printf("%d\t", getItem(m, i, j));
    }
    printf("\n");
  }
}

int main() {
  int i, j, size, item;
  struct Matrix *m;
  printf("Enter the size: ");
  scanf("%d", &size);

  m = initialize(size);

  for(i = 1; i <= size; i++) {
    for(j = 1; j <= i; j++) {
      printf("Enter item for row:%d, col: %d : ", i, j);
      scanf("%d", &item);
      setItem(m, i, j, item);
    }
  }
  display(m);
  return 0;
}
