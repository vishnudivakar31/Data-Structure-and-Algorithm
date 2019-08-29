/*
  Author: Vishnu Divakar
  Program: Bubble Sort
*/

#include<stdio.h>
#include<stdlib.h>
#include "array.h"

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
