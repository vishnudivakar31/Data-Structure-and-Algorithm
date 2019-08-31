//
//  HashTable.h
//  ChainHashing
//
//  Created by Vishnu Divakar on 8/31/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>
#include "LinkedList.h"

struct HashTable {
    struct LinkedList *table;
    int length;
};

struct HashTable getHashTable();

void hashItem(struct HashTable *ht, int item);

_Bool searchHashItem(struct HashTable *ht, int item);

_Bool deleteHashItem(struct HashTable *ht, int item);

#endif /* HashTable_h */
