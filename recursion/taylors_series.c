#include<stdio.h>

double taylorSeries(int x, int n) {
  static double p = 1, f = 1;
  double r;
  if(n == 0) {
    return 1;
  } else {
    r = taylorSeries(x, n - 1);
    p *= x;
    f *= n;
    return r + (p / f);
  }
}

int main(int argc, char const *argv[]) {
  printf("Taylor series for 4 iteration where x = 5 is %f.\n", taylorSeries(5, 4));
  return 0;
}
