//
//  main.c
//  ShellSort
//
//  Created by Vishnu Divakar on 8/31/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#include <stdio.h>
#include "Array.h"

void shellSort(struct Array *a) {
    int i, j, prev, gap, temp, *array = a->arr, current;
    gap = a->length / 2;
    while(gap > 0) {
        j = gap;
        for(i = 0; (i + gap) < a->length ; i++) {
            if(array[j] < array[i]) {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
                prev = i - gap;
                current = i;
                while(prev >= 0 && array[prev] > array[current]) {
                    temp = array[current];
                    array[current] = array[prev];
                    array[prev] = temp;
                    current = prev;
                    prev -= gap;
                }
            }
            j++;
        }
        gap /= 2;
    }
}

int main(int argc, const char * argv[]) {
    int item, i, n;
    struct Array *a;
    printf("Enter the size: ");
    scanf("%d", &n);
    a = createArray(n);
    for(i = 0; i < n; i++) {
        printf("Enter the item: ");
        scanf("%d", &item);
        addItems(a, item);
    }
    shellSort(a);
    displayArray(a);
    return 0;
}
