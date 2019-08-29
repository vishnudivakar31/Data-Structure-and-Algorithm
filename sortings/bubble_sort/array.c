
/*
  Author: Vishnu Divakar
  Program: Impl for array.h
*/

#include<stdio.h>
#include<stdlib.h>
#include "array.h"

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

void destoryArray(struct Array *a) {
  free(a->arr);
  free(a);
}
