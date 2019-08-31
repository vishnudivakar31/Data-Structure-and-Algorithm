//
//  Array.h
//  MergeSort
//
//  Created by Vishnu Divakar on 8/30/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <stdio.h>

struct Array {
    int *arr;
    int size;
    int length;
};

struct Array * createArray(int n);

void addItems(struct Array *a, int item);

void displayArray(struct Array *a);

#endif /* Array_h */
