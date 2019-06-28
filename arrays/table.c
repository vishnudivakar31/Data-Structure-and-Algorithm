#include<stdio.h>
#include<stdlib.h>

int main() {
  int **ptr, row, col, i, j;

  printf("Enter the no. of rows: ");
  scanf("%d", &row);

  printf("Enter the no. of cols: ");
  scanf("%d", &col);

  ptr = (int **) malloc(row * sizeof(int *));

  for(i = 0; i < col; i++) {
    ptr[i] = (int *) malloc(col * sizeof(int));
  }

  for(i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      printf("Enter the data for row: %d & col: %d: ", i + 1, j + 1);
      scanf("%d", &ptr[i][j]);
    }
  }

  printf("Display\n");

  for(i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      printf("%d.\t", ptr[i][j]);
    }
    printf("\n");
  }

  return 0;

}
