#include<stdio.h>
#include<stdlib.h>

struct Element {
  int row;
  int col;
  int item;
};

struct SparseMatrix {
  int totalRows;
  int totalCols;
  int totalNonZeroElem;
  struct Element *elements;
};

void initialize(struct SparseMatrix *sm, int **data, int rowCount, int colCount) {
  int i, j, totalElem = 0, k = 0;
  struct Element *element = (struct Element *) malloc(sizeof(struct Element));
  for(i = 0; i < rowCount; i++) {
    for(j = 0; j < colCount; j++) {
      if(data[i][j] != 0) {
        totalElem++;
        element = (struct Element *) realloc(element, totalElem * sizeof(struct Element));
        element[k].row = i;
        element[k].col = j;
        element[k].item = data[i][j];
        k++;
      }
    }
  }
  sm->totalRows = rowCount;
  sm->totalCols = colCount;
  sm->totalNonZeroElem = totalElem;
  sm->elements = element;
}

void display(struct SparseMatrix *sm) {
  int i, j, k = 0;
  struct Element *e = sm->elements;
  for(i = 0; i < sm->totalRows; i++) {
    for(j = 0; j < sm->totalCols; j++) {
      if(i ==  e[k].row && j == e[k].col) {
        printf("%d\t", e[k++].item);
      } else {
        printf("0\t");
      }
    }
    printf("\n");
  }
}

void destroy(int **data, int totalRows) {
  int i;
  for(i = 0; i < totalRows; i++) {
    free(data[i]);
  }
  free(data);
}

struct SparseMatrix add(struct SparseMatrix *m1, struct SparseMatrix *m2) {
  int i = 0, j = 0, k = 0;
  struct SparseMatrix sum;
  struct Element *e = (struct Element *) malloc(sizeof(struct Element));
  while(i < m1 -> totalNonZeroElem && j < m2 -> totalNonZeroElem) {
    e = (struct Element *) realloc(e, (k + 1) * sizeof(struct SparseMatrix));
    if(m1->elements[i].row < m2->elements[j].row) {
      e[k++] = m1->elements[i++];
    } else if(m2->elements[j].row < m1->elements[i].row) {
      e[k++] = m2->elements[j++];
    } else {
      if(m1->elements[i].col < m2->elements[j].col) {
        e[k++] = m1->elements[i++];
      } else if(m2->elements[j].col < m1->elements[i].col) {
        e[k++] = m2->elements[j++];
      } else {
        e[k].row = m1->elements[i].row;
        e[k].col = m1->elements[i].col;
        e[k].item = m1->elements[i].item + m2->elements[j].item;
        k++;
        i++;
        j++;
      }
    }
  }
  for(; i < m1->totalNonZeroElem; i++) e[k++] = m1->elements[i];
  for(; j < m2->totalNonZeroElem; j++) e[k++] = m2->elements[j];
  sum.totalRows = m1->totalRows;
  sum.totalCols = m1->totalCols;
  sum.totalNonZeroElem = k;
  sum.elements = e;
  return sum;
}

int main() {
  struct SparseMatrix sm1, sm2,sum;
  int i, j, totalRows, totalCols, **data, item;

  printf("Enter the no of rows: ");
  scanf("%d", &totalRows);

  printf("Enter the no of cols: ");
  scanf("%d", &totalCols);

  data = (int **) malloc(totalRows * sizeof(int *));
  for(i = 0; i < totalRows; i++) {
    data[i] = (int *) malloc(totalCols * sizeof(int));
  }

  for(i = 0; i < totalRows; i++) {
    for(j = 0; j < totalCols; j++) {
      printf("Enter the element for row: %d and col: %d: ", i + 1, j + 1);
      scanf("%d", &item);
      data[i][j] = item;
    }
  }

  initialize(&sm1, data, totalRows, totalCols);
  initialize(&sm2, data, totalRows, totalCols);
  destroy(data, totalRows);

  sum = add(&sm1, &sm2);

  display(&sm1);
  display(&sm2);
  display(&sum);

  return 0;
}
