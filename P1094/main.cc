#include <cstdio>
#include <algorithm>

int main() {
  int w, n, a[30001];
  scanf("%d %d", &w, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  
  std::sort(a, a+n);

  int i = 0, j = n-1, ans = 0;
  while (i <= j) {
    // printf("a[%d]=%d,a[%d]=%d\n", i, a[i], j, a[j]);
    if (a[i] + a[j] <= w) {
      i++;
      j--;
    } else {
      j--;
    }
    ans++;
  }
  printf("%d", ans);
  return 0;
}