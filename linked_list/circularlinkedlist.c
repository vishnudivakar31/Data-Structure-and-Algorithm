#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct CircularLinkedList {
  struct Node *head;
  struct Node *tail;
  int length;
};

void initialize(struct CircularLinkedList *cll) {
  cll->head = NULL;
  cll->tail = NULL;
  cll->length = 0;
}

void append(struct CircularLinkedList *cll, int data) {
  struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
  newNode->data = data;
  if(cll->head == NULL) {
    cll->head = newNode;
    cll->tail = newNode;
  } else {
    cll->tail->next = newNode;
    cll->tail = newNode;
  }
  newNode->next = cll->head;
  cll->length += 1;
}

int delete(struct CircularLinkedList *cll, int index) {
  int result = -1, i;
  struct Node *currNode = cll->head, *prevNode = NULL;
  if(cll->length > 0 && index > 0 && index << cll->length) {
    if(index == 1) {
      result = cll->head->data;
      currNode = cll->head;
      cll->head = cll->head->next;
      cll->tail->next = cll->head;
    } else {
      for(i = 1; i < index; i++) {
        prevNode = currNode;
        currNode = currNode->next;
      }
      result = currNode->data;
      if(currNode == cll->tail) {
        prevNode->next = cll->head;
        cll->tail = prevNode;
      } else {
        prevNode->next = currNode->next;
      }
    }
    free(currNode);
    cll->length -= 1;
  }
  return result;
}

void display(struct CircularLinkedList *cll) {
  struct Node *currNode = cll->head;
  if(currNode != NULL) {
    do {
      printf("%d\n", currNode->data);
      currNode = currNode->next;
    } while(currNode != cll->head);
    printf("Size of list is %d.\n", cll->length);
  }
}

int menu() {
  int choice;
  printf("**********\n");
  printf("** MENU **\n");
  printf("**********\n");
  printf("1.Add Item\n");
  printf("2.Display Items\n");
  printf("3.Delete Item\n");
  printf("4.Exit\n");
  printf("Enter your choice(1 - 4): ");
  scanf("%d", &choice);
  return choice;
}

void operations(struct CircularLinkedList *cll, int choice) {
  int item;
  switch(choice) {
    case 1: printf("Enter data: ");
            scanf("%d", &item);
            append(cll, item);
            break;
    case 2: display(cll);
            break;
    case 3: printf("Enter index: ");
            scanf("%d", &item);
            printf("Deleted item: %d.\n", delete(cll, item));
            break;
    case 4: printf("Closing....\n");
            break;
    default: printf("Invalid entry...\n");
  }
}

int main() {
  struct CircularLinkedList cll;
  int choice = 0;
  initialize(&cll);
  do {
    choice = menu();
    operations(&cll, choice);
  } while(choice != 4);
  return 0;
}
