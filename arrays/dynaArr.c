#include<stdio.h>
#include<stdlib.h>

int* incSize(int *arr, int oldSize, int newSize) {
    int i = 0;
    int *temp = (int *) malloc(newSize * sizeof(int));
    for(; i < oldSize; i++) {
      temp[i] = arr[i];
    }
    free(arr);
    arr = temp;
    temp = NULL;
    return arr;
}

int main() {
  int *arr, size, i, newSize;

  printf("Enter the size of array: ");
  scanf("%d", &size);

  arr = (int *) malloc(size * sizeof(int));

  for(i = 0; i < size; i++) {
      printf("Enter the elements to save: ");
      scanf("%d", &arr[i]);
  }

  for(i = 0; i < size; i++) {
      printf("Elements are: %d.\n", arr[i]);
  }

  printf("Enter new array size: ");
  scanf("%d", &newSize);

  arr = incSize(arr, size, newSize);

  for(i = size; i < newSize; i++) {
    printf("Enter the elements to save: ");
    scanf("%d", &arr[i]);
  }

  for(i = 0; i < newSize; i++) {
      printf("Elements are: %d.\n", arr[i]);
  }

  free(arr);

  return 0;

}
