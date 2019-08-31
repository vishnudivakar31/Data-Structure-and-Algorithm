//
//  Array.c
//  MergeSort
//
//  Created by Vishnu Divakar on 8/30/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#include "Array.h"
#include <stdio.h>
#include <stdlib.h>

struct Array * createArray(int n) {
    struct Array *a = (struct Array *) malloc(sizeof(struct Array *));
    a->arr = (int *) malloc(n * sizeof(int));
    a->size = n;
    a->length = 0;
    return a;
}

void addItems(struct Array *a, int item) {
    if(a->length < a->size) {
        a->arr[a->length++] = item;
    }
}

void displayArray(struct Array *a) {
    int i;
    for(i = 0; i < a->length; i++) {
        printf("%d\n", a->arr[i]);
    }
}

void destroyArray(struct Array *a) {
    free(a->arr);
    free(a);
}
