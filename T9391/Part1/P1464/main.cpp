// 审题十分重要
// 或者说出题人语言表述不严谨

#include <cstdio>
#include <array>
using namespace std;

array<array<array<int, 21>, 21>, 21> arr;

int w(long long a, long long b, long long c) {
  if (a <= 0 || b <= 0 || c <= 0) {
    return 1;
  }
  if (a > 20 || b > 20 || c > 20) {
    return w(20, 20, 20);
  }
  if (arr[a][b][c]) return arr[a][b][c];
  if (a < b && b < c) {
    arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return arr[a][b][c];
  }
  arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  return arr[a][b][c];
}

int main() {
  // freopen("data.int", "r", stdin);
  long long a, b, c;
  if (a > 20) a = 21;
  if (b > 20) b = 21;
  if (c > 20) c = 21;
  while (scanf("%lld %lld %lld", &a, &b, &c) == 3 && !(a==-1&&b==-1&&c==-1)) {
    printf("w(%lld, %lld, %lld) = %d\n", a, b, c, w(a, b, c));
  }
  return 0;
}