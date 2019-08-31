//
//  LinkedList.h
//  ChainHashing
//
//  Created by Vishnu Divakar on 8/31/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>

struct Node {
    int item;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
    struct Node *rear;
    int length;
};

struct LinkedList getList();

void appendItem(struct LinkedList *ll, int item);

_Bool searchItem(struct LinkedList *ll, int item);

_Bool sortedSearchItem(struct LinkedList *ll, int item);

void sortAppend(struct LinkedList *ll, int item);

_Bool deleteItem(struct LinkedList *ll, int item);

void display(struct LinkedList *ll);

#endif /* LinkedList_h */
