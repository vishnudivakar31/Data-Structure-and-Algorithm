//
//  main.c
//  QuickSort
//
//  Created by Vishnu Divakar on 8/29/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
#include "array.h"

int partitionArray(struct Array *a, int start, int end) {
    int *array = a->arr;
    int i = start, j = end, pivot = array[start], temp;
    while(i < j) {
        while(array[i] <= pivot) {
            i++;
        }
        while(array[j] > pivot) {
            j--;
        }
        if(i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[j];
    array[j] = pivot;
    array[start] = temp;
    return j;
}

void quickSort(struct Array *a, int start, int end) {
    int k;
    if(start < end) {
        k = partitionArray(a, start, end);
        quickSort(a, start, k);
        quickSort(a, k + 1, end);
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
            case 3: quickSort(a, 0, a->length - 1);
                break;
            case 4: printf("Quiting...\n");
                break;
            default: printf("Invalid input\n");
        }
    } while(choice != 4);
    destoryArray(a);
    return 0;
}
