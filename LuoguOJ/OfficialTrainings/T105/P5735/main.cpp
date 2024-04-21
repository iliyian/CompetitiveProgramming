#include <cstdio>
#include <cmath>

double dist(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
  double a[3], b[3];
  for (int i = 0; i < 3; i++)
    scanf("%lf %lf", a + i, b + i);
  double d = dist(a[0], b[0], a[1], b[1])
    + dist(a[0], b[0], a[2], b[2])
    + dist(a[1], b[1], a[2], b[2]);
  printf("%.2lf", d);
  return 0;
}