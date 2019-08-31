//
//  LinkedList.c
//  ChainHashing
//
//  Created by Vishnu Divakar on 8/31/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

struct LinkedList getList() {
    struct LinkedList ll;
    ll.head = NULL;
    ll.rear = NULL;
    ll.length = 0;
    return ll;
}

void appendItem(struct LinkedList *ll, int item) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->item = item;
    newNode->next = NULL;
    ll->length++;
    if(ll->head == NULL) {
        ll->head = newNode;
        ll->rear = newNode;
    } else {
        ll->rear->next = newNode;
        ll->rear = newNode;
    }
}

void sortAppend(struct LinkedList *ll, int item) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node)), *currNode = ll->head, *prevNode = NULL;
    newNode->item = item;
    newNode->next = NULL;
    ll->length++;
    if(ll->head == NULL) {
        ll->head = newNode;
        ll->rear = newNode;
    } else {
        while(currNode != NULL) {
            if(item < currNode->item) {
                newNode->next = currNode;
                if(prevNode == NULL) {
                    ll->head = newNode;
                } else {
                    prevNode->next = newNode;
                }
                if(ll->rear == currNode) {
                    ll->rear = newNode;
                }
                return;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }
        ll->rear->next = newNode;
        ll->rear = newNode;
    }
}

_Bool deleteItem(struct LinkedList *ll, int item) {
    struct Node *currNode = ll->head, *prevNode = NULL;
    while(currNode != NULL) {
        if(currNode->item == item) {
            if(prevNode == NULL) {
                ll->head = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode);
            ll->length--;
            return 1;
        }
        currNode = currNode->next;
    }
    return 0;
}

void display(struct LinkedList *ll) {
    struct Node *currNode = ll->head;
    while(currNode != NULL) {
        printf("%d\n", currNode->item);
        currNode = currNode->next;
    }
}

_Bool searchItem(struct LinkedList *ll, int item) {
    struct Node *currNode = ll->head;
    while(currNode != NULL) {
        if(currNode->item == item) {
            return 1;
        }
        currNode = currNode->next;
    }
    return 0;
}

_Bool sortedSearchItem(struct LinkedList *ll, int item) {
    struct Node *currNode = ll->head;
    while(currNode != NULL) {
        if(currNode->item == item) {
            return 1;
        }
        if(currNode->item > item) {
            return 0;
        }
        currNode = currNode->next;
    }
    return 0;
}
