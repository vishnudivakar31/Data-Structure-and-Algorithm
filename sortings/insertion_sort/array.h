/*
  Author: Vishnu Divakar
  Program: Array.h
*/

#ifndef Array_H
#define Array_H

struct Array {
  int *arr;
  int size;
  int length;
};

struct Array* createArray(int length);
void addElem(struct Array *a, int item);
void displayArray(struct Array *a);
void destoryArray(struct Array *a);

#endif
