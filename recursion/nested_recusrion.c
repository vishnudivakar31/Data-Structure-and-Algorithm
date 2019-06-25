#include<stdio.h>

int fun(int n) {
  if(n > 100) {
    return n - 10;
  } else {
    fun(fun(n + 11));
  }
}

int main(int argc, char const *argv[]) {
  printf("%d\n", fun(97));
  return 0;
}
