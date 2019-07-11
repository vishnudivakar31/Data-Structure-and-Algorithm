#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  struct Node *tail;
  int length;
};

void initialize(struct LinkedList *ll) {
  ll->head = NULL;
  ll->tail = NULL;
  ll->length = 0;
}

void append(struct LinkedList *ll, int data) {
  struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if(ll->head == NULL) {
    ll->head = newNode;
    ll->tail = newNode;
  } else {
    ll->tail->next = newNode;
    ll->tail = newNode;
  }
  ll->length++;
}

struct Node* findMiddleElement(struct LinkedList *ll) {
  struct Node *currNode = ll->head, *tailNode = ll->head;
  while (currNode != NULL) {
    currNode = currNode->next;
    if(currNode) {
      currNode = currNode->next;
    }
    if(currNode) {
      tailNode = tailNode->next;
    }
  }
  return tailNode;
}

void display(struct LinkedList *ll) {
  struct Node *currNode = ll->head;
  while(currNode) {
    printf("%d\n", currNode->data);
    currNode = currNode->next;
  }
}

int menu() {
  int choice;
  printf("1.Add item\n");
  printf("2.Display item\n");
  printf("3.Middle element\n");
  printf("4.Exit\n");
  printf("Enter your choice(1 - 4): ");
  scanf("%d", &choice);
  return choice;
}

void operation(struct LinkedList *ll, int choice) {
  int item;
  switch (choice) {
    case 1: printf("Enter data: ");
            scanf("%d", &item);
            append(ll, item);
            break;
    case 2: display(ll);
            break;
    case 3: printf("Middle item: %d.\n", findMiddleElement(ll)->data);
            break;
    case 4: printf("Closing.\n");
            break;
    default: printf("Invalid choice.\n");
  }
}

int main() {
  struct LinkedList ll;
  int choice;
  initialize(&ll);
  do {
    choice = menu();
    operation(&ll, choice);
  } while(choice != 4);
  return 0;
}
