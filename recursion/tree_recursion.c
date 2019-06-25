#include<stdio.h>

void fun(int n) {
  if(n > 0) {
    printf("No: %d\n", n);
    fun(n - 1);
    fun(n - 1);
  }
}

int main(int argc, char const *argv[]) {
  fun(5);
  return 0;
}
