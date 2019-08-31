//
//  HashTable.c
//  ChainHashing
//
//  Created by Vishnu Divakar on 8/31/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#include <stdlib.h>
#include "HashTable.h"

#define HASH_FUN(X) (X % 10)

struct HashTable getHashTable() {
    struct HashTable hash;
    int i;
    hash.table = (struct LinkedList *) malloc(10 * sizeof(struct LinkedList));
    hash.length = 0;
    for(i = 0; i < 10; i++) {
        hash.table[i] = getList();
    }
    return hash;
}

void hashItem(struct HashTable *ht, int item) {
    int index = HASH_FUN(item);
    sortAppend(&ht->table[index], item);
    ht->length++;
}

_Bool searchHashItem(struct HashTable *ht, int item) {
    int index = HASH_FUN(item);
    return searchItem(&ht->table[index], item);
}

_Bool deleteHashItem(struct HashTable *ht, int item) {
    int index = HASH_FUN(item);
    return deleteItem(&ht->table[index], item);
}
