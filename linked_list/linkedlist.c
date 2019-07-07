#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  struct Node *last;
  int length;
};

void initialize(struct LinkedList *ptr) {
  ptr->head = NULL;
  ptr->last = NULL;
  ptr->length = 0;
}

void append(struct LinkedList *ptr, int data) {
  struct Node *node = (struct Node *) malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  if(ptr->head == NULL) {
    ptr->head = node;
  } else {
    ptr->last->next = node;
  }
  ptr->last = node;
  ptr->length += 1;
}

void display(struct LinkedList *ptr) {
  struct Node *currNode = ptr->head;
  while(currNode != NULL) {
    printf("%d\n", currNode->data);
    currNode = currNode->next;
  }
}

void addItem(struct LinkedList *ptr) {
  int item;
  printf("Enter item to add: ");
  scanf("%d", &item);
  append(ptr, item);
}

int sumLinkedList(struct LinkedList *ptr) {
  int sum = 0;
  struct Node *currPtr = ptr->head;
  while(currPtr != NULL) {
    sum += currPtr->data;
    currPtr = currPtr->next;
  }
  return sum;
}

int maxLinkedList(struct LinkedList *ptr) {
  int max = ptr->head->data;
  struct Node *currPtr = ptr->head->next;
  while(currPtr != NULL) {
    if(currPtr->data > max) {
      max = currPtr->data;
    }
    currPtr = currPtr->next;
  }
  return max;
}

int minLinkedList(struct LinkedList *ptr) {
  int min = ptr->head->data;
  struct Node *currPtr = ptr->head->next;
  while(currPtr != NULL) {
    if(currPtr->data < min) {
      min = currPtr->data;
    }
    currPtr = currPtr->next;
  }
  return min;
}

struct Node* searchLinkedList(struct LinkedList *ptr, int key) {
  struct Node *currNode = ptr->head;
  while (currNode != NULL) {
    if(currNode->data == key) {
      return currNode;
    }
    currNode = currNode->next;
  }
  return NULL;
}

void insert(struct LinkedList *ptr, int data, int index) {
  if(index < 0 || index > ptr->length) {
    return;
  }
  struct Node *currNode = ptr->head, *newNode = (struct Node *) malloc(sizeof(struct Node));
  int i;
  newNode->data = data;
  if(index == 0) {
    newNode->next = ptr->head;
    ptr->head = newNode;
  } else {
    for(i = 1; i < index; i++) {
      currNode = currNode->next;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
  }
  ptr->length += 1;
}

void insertSorted(struct LinkedList *ptr, int data) {
  struct Node *newNode = (struct Node *) malloc(sizeof(struct Node)), *currNode = ptr->head, *prevNode = NULL;
  if(ptr->head == NULL) {
    append(ptr, data);
  } else {
    newNode->data = data;
    while(currNode != NULL && currNode->data < data) {
      prevNode = currNode;
      currNode = currNode->next;
    }
    if(prevNode == NULL) {
      newNode->next = ptr->head;
      ptr->head = newNode;
    } else {
      prevNode->next = newNode;
      newNode->next = currNode;
    }
  }
}

int delete(struct LinkedList *ptr, int index) {
  if(index < 1 || index > ptr->length || index > ptr->length) {
    return -1;
  }
  int i, item;
  struct Node *currNode = ptr->head, *prevNode = NULL;
  for(i = 0; i < index - 1; i++) {
    prevNode = currNode;
    currNode = currNode->next;
  }
  if(prevNode == NULL) {
    item = currNode->data;
    ptr->head = currNode->next;
    free(currNode);
  } else {
    item = currNode->data;
    prevNode->next = currNode->next;
    free(currNode);
  }
  ptr->length -= 1;
  return item;
}

int isSorted(struct LinkedList *ptr) {
  int x = -65536;
  struct Node *currNode = ptr->head;
  while(currNode != NULL) {
    if(currNode->data < x) {
      return -1;
    }
    x = currNode->data;
    currNode = currNode->next;
  }
  return 1;
}

int menu() {
  int choice;
  printf("**********\n");
  printf("** MENU **\n");
  printf("**********\n");
  printf("1. Add Item.\n");
  printf("2. Display Items.\n");
  printf("3. Show size of data.\n");
  printf("4. Show sum of elements.\n");
  printf("5. Show max of elements.\n");
  printf("6. Show min of elements.\n");
  printf("7. Search element.\n");
  printf("8. Insert element at a postion.\n");
  printf("9. Insert element in a sorted way.\n");
  printf("10. Delete data.\n");
  printf("11. Exit.\n");
  printf("Enter the choice(1 - 11): ");
  scanf("%d", &choice);
  return choice;
}

int main() {
  struct LinkedList ll;
  int choice = 0, key, data;
  initialize(&ll);
  do {
    choice = menu();
    switch (choice) {
      case 1: addItem(&ll);
              break;
      case 2: display(&ll);
              break;
      case 3: printf("Size of list: %d.\n", ll.length);
              break;
      case 4: printf("Sum of list: %d.\n", sumLinkedList(&ll));
              break;
      case 5: printf("Max of list: %d.\n", maxLinkedList(&ll));
              break;
      case 6: printf("Min of list: %d.\n", minLinkedList(&ll));
              break;
      case 7: printf("Enter the key to search: "),
              scanf("%d", &key);
              printf("Key is %s\n", searchLinkedList(&ll, key) == NULL ? "not found." : "is found.");
              break;
      case 8: printf("Enter the data: ");
              scanf("%d", &data);
              printf("Enter the index: ");
              scanf("%d", &key);
              insert(&ll, data, key);
              break;
      case 9: printf("Enter the data: ");
              scanf("%d", &data);
              insertSorted(&ll, data);
              break;
      case 10: printf("Enter the index to delete: ");
               scanf("%d", &key);
               printf("Item %s.\n", delete(&ll, key) == -1 ? "not deleted. Please check." : "is deleted");
               break;
      case 11: printf("Closing...\n");
              break;
      default: printf("Invalid Choice.\n");
    }
  } while(choice != 11);
  return 0;
}
