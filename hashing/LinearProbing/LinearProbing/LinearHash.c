//
//  LinearHash.c
//  LinearProbing
//
//  Created by Vishnu Divakar on 9/3/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#include "LinearHash.h"
#include <stdlib.h>

#define HASH(x) x % 10

struct HashTable getHashTable() {
    struct HashTable ht;
    ht.arr = (int *) calloc(10, sizeof(int));
    ht.size = 0;
    return ht;
}

int linearProb(int item, int i) {
    return (HASH(item) + i) % 10;
}

void hashItem(struct HashTable *ht, int item) {
    int index, i = 0;
    if(ht->size <= 10) {
        index = linearProb(item, i);
        while(ht->arr[index] != 0) {
            i++;
            index = linearProb(item, i);
        }
        ht->arr[index] = item;
        ht->size++;
    }
}

_Bool isPresent(struct HashTable *ht, int item) {
    int index = 0, i = 0;
    index = linearProb(item, i);
    while(ht->arr[index] != 0) {
        if(ht->arr[index] == item) {
            return 1;
        }
        i++;
        index = linearProb(item, i);
    }
    return 0;
}
