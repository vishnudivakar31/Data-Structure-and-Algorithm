#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  int col;
  struct Node *next;
};

struct SpareMatrix {
  struct Node **matrix;
  int row, col;
};

void initialize(struct SpareMatrix *sm, int row, int col) {
  int i = 0;
  sm->row = row;
  sm->col = col;
  sm->matrix = (struct Node **) malloc(row * sizeof(struct Node *));
  for(i = 0; i < col; i++) {
    sm->matrix[i] = (struct Node *) malloc(col * sizeof(struct Node));
    sm->matrix[i] = NULL;
  }
}

void insert(struct SpareMatrix *sm, int row, int col, int data) {
  struct Node *currNode = sm->matrix[row], *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->col = col;
  newNode->data = data;
  if(currNode == NULL) {
    sm->matrix[row] = newNode;
  } else {
    while(currNode->next != NULL) {
      currNode = currNode->next;
    }
    currNode->next = newNode;
  }
}

int get(struct SpareMatrix *sm, int row, int col) {
  struct Node *currNode = sm->matrix[row];
  while(currNode != NULL) {
    if(currNode->col == col) {
      return currNode->data;
    } else {
      return 0;
    }
    currNode = currNode->next;
  }
  return 0;
}

void display(struct SpareMatrix *sm) {
  int i, j;
  for(i = 0; i < sm->row; i++) {
    for(j = 0; j < sm->col; j++) {
      printf("%d\t", get(sm, i, j));
    }
    printf("\n");
  }
}

int main() {
  struct SpareMatrix sm;
  int row, col, i, j, data;

  printf("Enter the number of rows: ");
  scanf("%d", &row);
  printf("Enter the number of cols: ");
  scanf("%d", &col);

  initialize(&sm, row, col);

  for(i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      printf("Enter the data for row: %d, col: %d: ", i + 1, j + 1);
      scanf("%d", &data);
      if(data != 0) {
        insert(&sm, i, j ,data);
      }
    }
  }
  display(&sm);
}
