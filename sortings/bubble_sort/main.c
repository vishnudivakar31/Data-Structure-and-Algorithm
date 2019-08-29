/*
  Author: Vishnu Divakar
  Program: Bubble Sort
*/

#include<stdio.h>
#include<stdlib.h>

struct Array {
  int *arr;
  int size;
  int length;
};

struct Array* createArray(int length) {
  struct Array *newArr = (struct Array *) malloc(sizeof(struct Array));
  newArr->arr = (int *) malloc(length * sizeof(int));
  newArr->size = length;
  newArr->length = 0;
  return newArr;
}

void addElem(struct Array *a, int item) {
  if(a->length < a->size) {
    a->arr[a->length++] = item;
  }
}

void displayArray(struct Array *a) {
  int i = 0;
  for(; i < a->length; i++) {
    printf("%d\n", a->arr[i]);
  }
}

void sort(struct Array *a) {
  int i, j, temp;
  int *array = a->arr;
  for(i = 0; i < a->length; i++) {
    for(j = 0; j < (a->length - i - 1); j++) {
      if(array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void destoryArray(struct Array *a) {
  free(a->arr);
  free(a);
}

int main() {
  int size, item, choice = 0;
  struct Array *a;

  printf("Enter the size of array: ");
  scanf("%d", &size);

  a = createArray(size);

  do {
    printf("***MENU***\n");
    printf("1. Add Element\n");
    printf("2. Display Array\n");
    printf("3. Sort Array\n");
    printf("4. Exit\n");
    printf("Enter your choice(1 - 4): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: printf("Enter item: ");
              scanf("%d", &item);
              addElem(a, item);
              break;
      case 2: displayArray(a);
              break;
      case 3: sort(a);
              break;
      case 4: printf("Quiting...\n");
              break;
      default: printf("Invalid input\n");
    }
  } while(choice != 4);
  destoryArray(a);
  return 0;
}
