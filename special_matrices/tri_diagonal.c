#include<stdio.h>
#include<stdlib.h>

struct Matrix {
  int *p;
  int size;
};

struct Matrix * initialize(int size) {
  struct Matrix *m = (struct Matrix *) malloc(sizeof(struct Matrix));
  m->p = (int *) malloc(size * sizeof(int));
  m->size = size;
  return m;
}

void destroy(struct Matrix *m) {
  free(m->p);
  free(m);
}

void setItem(struct Matrix *m, int i, int j, int item) {
  if(i - j == 1) {
    m->p[i - 2] = item;
  } else if(i - j == 0) {
    m->p[(m->size - 1) + (i - 1)] = item;
  } else if(i - j == -1) {
    m->p[((2 * m->size) - 1) + i - 1] = item;
  }
}

int getItem(struct Matrix *m, int i, int j) {
  if(i - j == 1) {
    return m->p[i - 2];
  } else if(i - j == 0) {
    return m->p[(m->size - 1) + (i - 1)];
  } else if(i - j == -1) {
    return m->p[((2 * m->size) - 1) + i - 1];
  }
  return 0;
}

void display(struct Matrix *m) {
  int i, j;
  for(i = 1; i <= m->size; i++) {
    for(j = 1; j <= m->size; j++) {
      printf("%d\t", getItem(m, i, j));
    }
    printf("\n");
  }
}

int main() {
  int size, item, i ,j;
  struct Matrix *m;

  printf("Enter the size: ");
  scanf("%d", &size);
  m = initialize(size);

  for(i = 1; i<= size; i++) {
    for(j = 1; j<= size; j++) {
      if((i - j == 1) || (i - j == 0) || (i - j == -1)) {
        printf("Enter element for row: %d, col: %d: ", i, j);
        scanf("%d", &item);
        setItem(m, i, j, item);
      }
    }
  }
  display(m);
  return 0;
}
