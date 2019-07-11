#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct DoubleLinkedList {
  struct Node *head;
  struct Node *tail;
  int lenght;
};

void initialize(struct DoubleLinkedList *dll) {
  dll->head = NULL;
  dll->tail = NULL;
  dll->lenght = 0;
}

void append(struct DoubleLinkedList *dll, int data) {
  struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  dll->lenght += 1;
  if(dll->head == NULL) {
    dll->head = newNode;
    dll->tail = newNode;
    newNode->prev = NULL;
  } else {
    dll->tail->next = newNode;
    newNode->prev = dll->tail;
    dll->tail = newNode;
  }
}

void insert(struct DoubleLinkedList *dll, int index, int data) {
  struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
  struct Node *currNode = dll->head;
  int i;
  newNode->data = data;

  if(index >= 0) {
    if(currNode == NULL || index == dll->lenght) {
      if(index == 0) {
        newNode->prev = NULL;
        newNode->next = dll->head->next;
        dll->head = newNode;
      } else {
        newNode->prev = dll->tail;
        newNode->next = NULL;
      }
      dll->tail = newNode;
    } else if(index < dll->lenght) {
      for(i = 1; i <= index; i++, currNode = currNode->next);
      newNode->next = currNode->next->next;
      currNode->next = newNode;
      newNode->prev = currNode;
    }
    dll->lenght += 1;
  }
}

int delete(struct DoubleLinkedList *dll, int index) {
  struct Node *currNode = dll->head;
  int i, result = -1;
  if(currNode != NULL && index >= 1 && index <= dll->lenght) {
    if(index == 1) {
      dll->head = currNode->next;
      dll->head->prev = NULL;
    } else {
      for(i = 2; i <= index; i++) {
        currNode = currNode->next;
      }
      if(currNode == dll->tail) {
        dll->tail = currNode->prev;
        dll->tail->next = NULL;
      } else {
        currNode->prev->next = currNode->next;
      }
    }
    result = currNode->data;
    free(currNode);
    dll->lenght -= 1;
  }
  return result;
}

void display(struct DoubleLinkedList *dll) {
  struct Node *currNode = dll->head;
  printf("**** LIST ****\n");
  while(currNode != NULL) {
    printf("%d\n", currNode->data);
    currNode = currNode->next;
  }
  printf("*************\n");
}

int menu() {
  int choice;
  printf("**********\n");
  printf("** MENU **\n");
  printf("**********\n");
  printf("1.Add Item\n");
  printf("2.Display Items\n");
  printf("3.Insert Item\n");
  printf("4.Delete Item\n");
  printf("5.Exit\n");
  printf("Enter your choice(1 - 5): ");
  scanf("%d", &choice);
  return choice;
}

void operations(struct DoubleLinkedList *dll, int choice) {
  int item, index;
  switch(choice) {
    case 1: printf("Enter data: ");
            scanf("%d", &item);
            append(dll, item);
            break;
    case 2: display(dll);
            break;
    case 3: printf("Enter index: ");
            scanf("%d", &index);
            printf("Enter data: ");
            scanf("%d", &item);
            insert(dll, index, item);
            break;
    case 4: printf("Enter index: ");
            scanf("%d", &item);
            printf("Deleted item: %d.\n", delete(dll, item));
            break;
    case 5: printf("Closing....\n");
            break;
    default: printf("Invalid entry...\n");
  }
}

int main() {
  struct DoubleLinkedList dll;
  int choice = 0;
  initialize(&dll);
  do {
    choice = menu();
    operations(&dll, choice);
  } while(choice != 5);
}
