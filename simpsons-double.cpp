#include <time.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>




double pi;

double fun(double xarg) {
  double result;
  result = sin(pi * xarg);
  return result;
}

int main( int argc, char **argv) {


  const int n = 1000000;
  double a; double b;
  double h; double s1; double x; 

  a = 0.0;
  b = 1.0;
  pi = acos(-1.0);
  h = (b - a) / (2.0 * n);
  s1= 0.0;

  x = a;
  s1 = (fun(a) + fun(b));

  for(int l = 0; l < n; l++) { // ITERS before
    x += h;
    s1 = s1 + 4.0 * fun(x);
    x = x + h;
    s1 = s1 + 2.0 * fun(x);
  }
  s1 = s1 * h * pi /3;
  printf("ans: %.15e\n", s1);


  return 0;
}
