#include<stdio.h>
#include<stdlib.h>

int main() {
  int *p, *temp, numberOfElem, loopControl;

  printf("Enter the number of elements: ");
  scanf("%d", &numberOfElem);

  p = (int *) calloc(numberOfElem, sizeof(int));
  temp = p;
  loopControl = numberOfElem;

  /* Loading data to array */
  do {
      printf("Enter the element: ");
      scanf("%d", temp);
      temp++;
      loopControl--;
  } while(loopControl > 0);

  /* Displaying data to array */
  temp = p;
  printf("Elements are displayed below. Size of collections are %d\n", numberOfElem);
  for(; loopControl < numberOfElem; loopControl++) {
    printf("%d\n", *temp);
    temp++;
  }

  free(p);

  return 0;
}
