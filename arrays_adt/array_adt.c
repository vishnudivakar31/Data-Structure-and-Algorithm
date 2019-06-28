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

void destroy(struct Array *arr) {
  free(arr->a);
  free(arr);
}

int main() {
  struct Array *arr;
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

  printf("The array is as follows: \n");
  display(arr);

  printf("Sum of arrays: %d\n", sum(arr));
  printf("Avg of arrays: %f\n", avg(arr));
  printf("Max of arrays: %d\n", max(arr));
  printf("Min of arrays: %d\n", min(arr));

  printf("Array Reversed.\n");
  reverse(arr);
  display(arr);

  printf("Array left shifted.\n");
  leftShift(arr);
  display(arr);

  printf("Array left rotated.\n");
  leftRotate(arr);
  display(arr);

  destroy(arr);
  return 0;
}
