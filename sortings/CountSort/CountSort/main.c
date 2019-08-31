//
//  main.c
//  CountSort
//
//  Created by Vishnu Divakar on 8/30/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

int findMax(struct Array *a) {
    int max = a->arr[0], i;
    for(i = 0; i < a->length; i++) {
        if(a->arr[i] > max) {
            max = a->arr[i];
        }
    }
    return max;
}

void countSort(struct Array *a) {
    int *temp, max, i, k = 0;
    max = findMax(a);
    temp = (int *) calloc((max + 1), sizeof(int));
    for(i = 0; i < a->length; i++) {
        temp[a->arr[i]]++;
    }
    for(i = 0; i <= max; i++) {
        while(temp[i] > 0) {
            a->arr[k++] = i;
            temp[i]--;
        }
    }
    free(temp);
}

int main(int argc, const char * argv[]) {
    struct Array *a;
    int n, item, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    a = createArray(n);
    for(i = 0; i < n; i++) {
        printf("Enter item: ");
        scanf("%d", &item);
        addItems(a, item);
    }
    countSort(a);
    displayArray(a);
    return 0;
}
