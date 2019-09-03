//
//  LinearHash.h
//  LinearProbing
//
//  Created by Vishnu Divakar on 9/3/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#ifndef LinearHash_h
#define LinearHash_h

#include <stdio.h>

struct HashTable {
    int *arr;
    int size;
};

struct HashTable getHashTable();

void hashItem(struct HashTable *ht, int item);

_Bool isPresent(struct HashTable *ht, int item);

#endif /* LinearHash_h */
