#include<stdio.h>
#include<stdlib.h>

struct Array {
  int *a;
  int length;
  int size;
};

struct Array* initialize(int size) {
  struct Array *ptr = (struct Array *) malloc(sizeof(struct Array));
  ptr->a = (int *) malloc(size * sizeof(int));
  ptr->length = 0;
  ptr->size = size;
  return ptr;
}

int append(struct Array *arr, int item) {
  if(arr->length == arr->size) {
    return -1;
  }
  arr->a[arr->length] = item;
  arr->length += 1;
  return 1;
}

int findMissingElement(struct Array *arr) {
  int i = 0, diff = arr->a[0] - 0;
  for(; i < arr->length; i++) {
    if(arr->a[i] - i != diff) {
      return i + diff;
    }
  }
  return -1;
}

void findMissingElementsSorted(struct Array *arr) {
  int i = 0, diff = arr->a[0] - 0;
  for(; i < arr->length; i++) {
    if(arr->a[i] - i != diff) {
      while(diff < arr->a[i] - i) {
        printf("Missing element is %d.\n", diff + i);
        diff++;
      }
    }
  }
}

void findMissingElementUnSorted(struct Array *arr) {
  int *ptr, max = arr->a[0], i = 1;
  for(; i < arr->length; i++) {
    if(arr->a[i] > max) {
      max = arr->a[i];
    }
  }
  printf("Max: %d\n", max);
  ptr = (int *) calloc(max + 1, sizeof(int));

  for(i = 0; i < arr->length; i++) {
    ptr[arr->a[i]] += 1;
  }

  printf("Missing Elements.\n");
  for(i = 0; i <= max; i++) {
    if(ptr[i] == 0) {
        printf("Item: %d\n", i);
    }
  }
  free(ptr);
}

void findDuplicates(struct Array *arr) {
  int *ptr, max = arr->a[0], i = 0;
  for(i = 1; i < arr->length; i++) {
    if(arr->a[i] > max) {
      max = arr->a[i];
    }
  }

  ptr = (int *) calloc(max + 1, sizeof(int));
  for(i = 0; i < arr->length; i++) {
    ptr[arr->a[i]] += 1;
  }

  printf("Duplicate Items are:\n");
  for(i = 0; i <= max; i++) {
    if(ptr[i] > 1) {
      printf("Item: %d, Count: %d.\n", i, ptr[i]);
    }
  }
  free(ptr);
}

void findPair(struct Array *arr, int sum) {
  int *ptr, max = arr->a[0], i = 0;
  for(i = 1; i < arr->length; i++) {
    if(arr->a[i] > max) {
      max = arr->a[i];
    }
  }

  ptr = (int *) calloc(max + 1, sizeof(int));
  for(i = 0; i < arr->length; i++) {
    ptr[arr->a[i]] += 1;
  }

  printf("The pairs are as follows:\n");
  for(i = 0; i <= max; i++) {
    if(ptr[i] > 0 && ptr[sum - i] > 0 && i < (sum - i)) {
      printf("%d, %d.\n", i, sum - i);
    }
  }
  free(ptr);
}

void minMax(struct Array *arr) {
  int min = arr->a[0], max = arr->a[0], i = 0;
  for(i = 1; i < arr->length; i++) {
    if(arr->a[i] < min) {
      min = arr->a[i];
    }
    if(arr->a[i] > max) {
      max = arr->a[i];
    }
  }
  printf("Maximum: %d.\n", max);
  printf("Minimum: %d.\n", min);
}

int main(int argc, char const *argv[]) {
  struct Array *arr;
  int size = 0, i = 0, item = 0, length;

  printf("Enter the size of array: ");
  scanf("%d", &size);

  if(size <= 0) {
    return -1;
  }

  arr = initialize(size);

  printf("Enter no. of elements to insert: ");
  scanf("%d", &length);

  if(length <= 0 || length > size) {
    return -1;
  }

  for(; i < length; i++) {
    printf("Enter item, No: %d: ", i + 1);
    scanf("%d", &item);
    append(arr, item);
  }

  minMax(arr);

  return 0;
}
