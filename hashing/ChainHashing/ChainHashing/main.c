//
//  main.c
//  ChainHashing
//
//  Created by Vishnu Divakar on 8/31/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#include <stdio.h>
#include "HashTable.h"

int main(int argc, const char * argv[]) {
    struct HashTable ht = getHashTable();
    int item, choice;
    do {
        printf("**MENU**\n");
        printf("1. Add Item\n");
        printf("2. Search for item\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter item: ");
                    scanf("%d", &item);
                    hashItem(&ht, item);
                    break;
            case 2: printf("Enter item: ");
                    scanf("%d", &item);
                    printf("Item %s\n", searchHashItem(&ht, item) == 1 ? "found" : "not found");
                    break;
            case 3: printf("Quiting...\n");
                    break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 3);
    return 0;
}
