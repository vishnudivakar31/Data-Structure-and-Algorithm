#include<stdio.h>

int pow1(int base, int power) {
  if(power == 0) {
    return 1;
  }
  return pow1(base, power - 1) * base;
}

int main(int argc, char const *argv[]) {
  printf("5 ^ 3 = %d\n", pow1(5, 3));
  return 0;
}
