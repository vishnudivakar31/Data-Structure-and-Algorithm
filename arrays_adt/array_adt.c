#include<stdio.h>
#include<stdlib.h>

struct Array {
  int *a;
  int size;
  int length;
};

struct Array* initialize(int size) {
  struct Array *arr = (struct Array *) malloc(sizeof(struct Array));
  arr->size = size;
  arr->length = 0;
  arr->a = (int *) malloc(sizeof(int) * size);
  return arr;
}

int append(struct Array *arr, int item) {
  if(arr->length > arr->size) {
    return -1;
  }
  int length = arr->length;
  arr->a[length] = item;
  arr->length += 1;
  return 0;
}

struct Array * merge(struct Array *a1, struct Array *a2) {
  int a1Size = a1->length, a2Size = a2->length, i = 0, j = 0;
  struct Array *result = initialize(a1Size + a2Size);
  while(i < a1Size && j < a2Size) {
    if(a1->a[i] < a2->a[j]) {
      append(result, a1->a[i++]);
    } else {
      append(result, a2->a[j++]);
    }
  }
  for(; i < a1Size; i++) {
    append(result, a1->a[i]);
  }
  for(; j < a2Size; j++) {
    append(result, a2->a[j]);
  }
  return result;
}

int insert(struct Array *arr, int index, int item) {
  if(index >= arr->length || index < 0) {
    return -1;
  }
  int i = 0;
  for(i = arr->length; i > index; i--) {
    arr->a[i] = arr->a[i - 1];
  }
  arr->a[index] = item;
  arr->length += 1;
  return 1;
}

int delete(struct Array *arr, int index) {
  if(index >= arr->length || index < 0) {
    return -1;
  }
  int i = index;
  for(; i < arr->length; i++) {
    arr->a[i] = arr->a[i + 1] ;
  }
  arr->length -= 1;
  return 1;
}

int display(struct Array *arr) {
  int i = 0;
  for(; i < arr->length; i++) {
    printf("%d\n", arr->a[i]);
  }
  return arr->length;
}

int linearSearch(struct Array *arr, int key) {
  int i = 0;
  for(; i < arr->length; i++) {
    if(arr->a[i] == key) {
      return i;
    }
  }
  return -1;
}

int transpositionLS(struct Array *arr, int key) {
  int i = 0, temp = 0;
  for(; i < arr->length; i++) {
    if(arr->a[i] == key) {
      if(i != 0) {
        temp = arr->a[i];
        arr->a[i] = arr->a[i - 1];
        arr->a[i - 1] = temp;
      }
      return i - 1;
    }
  }
  return -1;
}

int moveToHeadLS(struct Array *arr, int key) {
  int i = 0, temp = 0;
  for(; i < arr->length; i++) {
    if(arr->a[i] == key) {
      if(i != 0) {
        temp = arr->a[i];
        arr->a[i] = arr->a[0];
        arr->a[0] = temp;
      }
      return 0;
    }
  }
  return -1;
}

int binarySearch(struct Array *arr, int key) {
  int low = 0, high = arr->length - 1, mid = (low + high) / 2, *a = arr->a;
  while(low <= high) {
    if(a[mid] == key) {
      return mid;
    }
    if(a[mid] > key) {
      high = mid - 1;
    }
    low = mid + 1;
    mid = (low + high) / 2;
  }
  return -1;
}

int get(struct Array *arr, int index) {
  if(index >= 0 && index < arr->length) {
    return arr->a[index];
  }
  return -1;
}

int set(struct Array *arr, int index, int item) {
  if(index >= 0 && index < arr->length) {
    arr->a[index] = item;
    return 1;
  }
  return -1;
}

float avg(struct Array *arr) {
  int i = 0;
  float sum = 0.0;
  for(; i < arr->length; i++) {
    sum += arr->a[i];
  }
  return sum / arr->length;
}

int sum(struct Array *arr) {
  int i = 0, sum = 0.0;
  for(; i < arr->length; i++) {
    sum += arr->a[i];
  }
  return sum;
}

int max(struct Array *arr) {
  int maxItem = arr->a[0], i = 1;
  for(; i < arr->length; i++) {
    if(maxItem < arr->a[i]) {
      maxItem = arr->a[i];
    }
  }
  return maxItem;
}

int min(struct Array *arr) {
  int minItem = arr->a[0], i = 1;
  for(; i < arr->length; i++) {
    if(minItem > arr->a[i]) {
      minItem = arr->a[i];
    }
  }
  return minItem;
}

void reverse(struct Array *arr) {
  int i = 0, j = arr->length - 1, temp = 0;
  while(i < j) {
    temp = arr->a[i];
    arr->a[i] = arr->a[j];
    arr->a[j] = temp;
    i++;
    j--;
  }
}

void leftShift(struct Array *arr) {
  int i = 0;
  for(; i < arr->length; i++) {
    arr->a[i] = arr->a[i + 1];
  }
  arr->a[i - 1] = 0;
}

void leftRotate(struct Array *arr) {
  int i = 0, temp = arr->a[i];
  for(; i < arr->length; i++) {
    arr->a[i] = arr->a[i + 1];
  }
  arr->a[i - 1] = temp;
}

int sortInsert(struct Array *arr, int item) {
  int i = arr->length - 1;
  for(; i >= 0 && arr->a[i] > item; i--) {
    arr->a[i + 1] = arr->a[i];
  }
  arr->a[i + 1] = item;
  arr->length += 1;
  return 1;
}

_Bool isSorted(struct Array *arr) {
  int i = 0;
  for(; (i < arr->length - 1) && (arr->a[i] < arr->a[i + 1]); i++);
  return i == (arr->length - 1);
}

void arrangeNegative(struct Array *arr) {
  int i = 0, j = arr->length - 1, temp = 0;
  while(i <= j) {
    while(arr->a[i] < 0 && i < arr->length) i++;
    while(arr->a[j] > 0 && j > 0) j--;
    temp = arr->a[i];
    arr->a[i] = arr->a[j];
    arr->a[j] = temp;
  }
}

struct Array* customUnion(struct Array *a1, struct Array *a2)  {
  int size1 = a1->length, size2 = a2->length, i = 0, j = 0;
  struct Array *result = initialize(size1 + size2);
  while (i < size1 && j < size2) {
    if(a1->a[i] < a2->a[j]) {
      append(result, a1->a[i++]);
    } else if(a2->a[j] < a1->a[i]) {
      append(result, a2->a[j++]);
    } else {
      append(result, a1->a[i++]);
      j++;
    }
  }
  for(; i < size1; i++) {
    append(result, a1->a[i]);
  }
  for(; j < size2; j++) {
    append(result, a2->a[j]);
  }
  return result;
}

struct Array* intersection(struct Array *a1. struct Array *a2) {
  int size1 = a1->length, size2 = a2->length, i = 0, j = 0;
  struct Array *result = initialize(size1 + size2);
  while (i < size1 && j < size2) {
    if(a1->a[i] < a2->a[j]) {
      i++;
    } else if(a2->a[j] < a1->a[1]) {
      j++;
    } else {
      append(result, a1->a[i++]);
      j++;
    }
  }
  return result;
}

struct Array* difference(struct Array *a1, struct Array *a2)  {
  int size1 = a1->length, size2 = a2->length, i = 0, j = 0;
  struct Array *result = initialize(size1 + size2);
  while (i < size1 && j < size2) {
    if(a1->a[i] < a2->a[j]) {
      append(result, a1->a[i++]);
    } else if(a2->a[j] < a1->a[i]) {
      j++;
    } else {
      i++;
      j++;
    }
  }
  for(; i < size1; i++) {
    append(result, a1->a[i]);
  }
  return result;
}

void destroy(struct Array *arr) {
  free(arr->a);
  free(arr);
}

int main() {
  struct Array *arr, *arr1, *result;
  int size = 0, length = 0, i = 0, item = 0, index = 0;

  printf("Enter the size of array req.: ");
  scanf("%d", &size);
  arr = initialize(size);

  printf("Enter the number of items to enter. (Should be less than or equal to %d): ", size);
  scanf("%d", &length);

  if(length > size) {
    return -1;
  }

  for(; i < length; i++) {
    printf("Enter item: ");
    scanf("%d", &item);
    append(arr, item);
  }

  /* 2nd Array */
  printf("Enter the size of array req.: ");
  scanf("%d", &size);
  arr1 = initialize(size);

  printf("Enter the number of items to enter. (Should be less than or equal to %d): ", size);
  scanf("%d", &length);

  if(length > size) {
    return -1;
  }

  for(i = 0; i < length; i++) {
    printf("Enter item: ");
    scanf("%d", &item);
    append(arr1, item);
  }
  /*************/

  printf("Array 1. \n");
  display(arr);

  printf("Array 2. \n");
  display(arr1);

  result = merge(arr, arr1);
  printf("Merged Array. \n");
  display(result);


  destroy(arr);
  destroy(arr1);
  destroy(result);
  return 0;
}
