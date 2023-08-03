#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, x, y;
  scanf("%lld/%lld", &a, &b);
  while (scanf("%lld/%lld", &x, &y) == 2) {
    long long t = __gcd(b, y);
    long long lcm = b * y / t;
    a *= lcm / b, x *= lcm / y;
    a += x;
    b = lcm;
  }
  long long t = __gcd(a, b);
  a /= t, b /= t;
  if (a == 0) printf("0");
  else if (b == 1) printf("%lld", a);
  else if (b < 0) printf("-%lld/%lld", a, -b);
  else printf("%lld/%lld", a, b);
  return 0;
}