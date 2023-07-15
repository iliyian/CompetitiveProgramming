#include <cstdio>
double a, b, c, d;

double cal(double x) {
  return a*x*x*x + b*x*x + c*x +d;
}

int main() {
  scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
  int s = 0;
  for (double l = -100; l <= 100 && s < 3; l += 0.001) {
    // printf("l=%lf, r=%lf\n", cal(l), cal(l+0.001));
    if (cal(l) * cal(l+0.001) < 0) {
      printf("%.2lf ", l+0.0005);
      s++;
    }
  }
  return 0;
}