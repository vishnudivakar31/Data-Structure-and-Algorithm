//
//  main.c
//  MergeSort
//
//  Created by Vishnu Divakar on 8/30/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

void merge(struct Array *a, int start, int mid, int last) {
    int i = start, j = mid + 1, k = start;
    int *b = (int *) malloc(a->size * sizeof(int));
    while(i <= mid && j <= last) {
        if(a->arr[i] <= a->arr[j]) {
            b[k++] = a->arr[i++];
        } else {
            b[k++] = a->arr[j++];
        }
    }
    for(; i <= mid; i++) {
        b[k++] = a->arr[i];
    }
    for(; j <= last; j++) {
        b[k++] = a->arr[j];
    }
    for(i = start; i <= last; i++) {
        a->arr[i] = b[i];
    }
    free(b);
}

void mergeSort(struct Array *a, int start, int last) {
    int i = start, j = last, mid = (start + last) / 2;
    if(i < j) {
        mergeSort(a, i, mid);
        mergeSort(a, mid + 1, j);
        merge(a, i, mid, j);
    }
}

int main(int argc, const char * argv[]) {
    int n, i, item;
    struct Array *a;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    a = createArray(n);
    for(i = 0; i < n; i++) {
        printf("Enter the item: ");
        scanf("%d", &item);
        addItems(a, item);
    }
    mergeSort(a, 0, n - 1);
    displayArray(a);
    return 0;
}
