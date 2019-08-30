//
//  array.h
//  QuickSort
//
//  Created by Vishnu Divakar on 8/29/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#ifndef array_h
#define array_h

struct Array {
    int *arr;
    int size;
    int length;
};

struct Array* createArray(int length);
void addElem(struct Array *a, int item);
void displayArray(struct Array *a);
void destoryArray(struct Array *a);

#endif /* array_h */
