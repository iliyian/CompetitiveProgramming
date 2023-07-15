#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  long long n, m = 0;
  scanf("%lld", &n);
  for (int i = 0; i < 16; i++) {
    m += pow(2, 16+i) * (n & 1);
    n >>= 1;
  }
  for (int i = 0; i < 16; i++) {
    m += pow(2, i) * (n & 1);
    n >>= 1;
  }
  printf("%lld", m);
  return 0;
}