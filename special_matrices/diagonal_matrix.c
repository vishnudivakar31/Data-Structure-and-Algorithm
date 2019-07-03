#include<stdio.h>
#include<stdlib.h>

struct DiagonalMatrix {
  int *a;
  int size;
};

struct DiagonalMatrix * initialize(int size) {
  struct DiagonalMatrix *dm = (struct DiagonalMatrix *) malloc(sizeof(struct DiagonalMatrix));
  dm->a = (int *) calloc(size, sizeof(int));
  dm->size = size;
  return dm;
}

void setItem(struct DiagonalMatrix *matrix, int i, int j, int item) {
  if(i == j) {
    matrix->a[i - 1] = item;
  }
}

int getItem(struct DiagonalMatrix *matrix, int i, int j) {
  if(i == j) {
    return matrix->a[i - 1];
  }
  return 0;
}

void display(struct DiagonalMatrix *matrix) {
  int i, j;
  for(i = 1; i <= matrix->size; i++) {
    for(j = 1; j <= matrix->size; j++) {
      printf("%d\t", getItem(matrix, i, j));
    }
    printf("\n");
  }
}

int main() {
  struct DiagonalMatrix *dm;
  int i, size, item;
  printf("Enter the size of square matrix: ");
  scanf("%d", &size);
  dm = initialize(size);
  for(i = 1; i <= size; i++) {
    printf("Enter element for row: %d, col: %d: ", i, i);
    scanf("%d", &item);
    setItem(dm, i, i, item);
  }
  display(dm);
  free(dm);
  return 0;
}
