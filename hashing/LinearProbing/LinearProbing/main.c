//
//  main.c
//  LinearProbing
//
//  Created by Vishnu Divakar on 9/3/19.
//  Copyright © 2019 Vishnu Divakar. All rights reserved.
//

#include <stdio.h>
#include "LinearHash.h"

int main(int argc, const char * argv[]) {
    int item, choice = 0;
    struct HashTable ht = getHashTable();
    do {
        printf("***MENU***\n");
        printf("1. Add item\n");
        printf("2. Search item\n");
        printf("3. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                hashItem(&ht, item);
                break;
            case 2:
                printf("Enter item: ");
                scanf("%d", &item);
                printf("%d is %s.\n", item, isPresent(&ht, item) == 1 ? "present." : "not present.");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 3);
    return 0;
}
