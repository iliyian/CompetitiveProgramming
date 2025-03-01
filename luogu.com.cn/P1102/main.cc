#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[200001];

// ans用long long 真坑
// 内置算法就是快

int main() {
  freopen("P1102_3.in", "r", stdin);
  freopen("data.out", "w", stdout);

  int n, c;
  // map<int, int> m;
  scanf("%d %d", &n, &c);
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    int b;
    scanf("%d", &b);
    a[i] = b;
  }

  std::sort(a, a+n);

  long long count = 0;
  for (int i = 0; i < n; i++) {
    count += upper_bound(a, a+n, a[i] + c) - lower_bound(a, a+n, a[i] + c);
  }
  
  printf("%lld", count);
  return 0;
}