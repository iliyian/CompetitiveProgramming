#include <cstdio>
#include <algorithm>

int main()
{
  int ans = 1, count = 1, n, prev = -100;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int cur;
    scanf("%d", &cur);
    if (prev + 1 == cur) ans = std::max(ans, ++count);
    else count = 1;
    prev = cur;
  }
  printf("%d", ans);
  return 0;
}