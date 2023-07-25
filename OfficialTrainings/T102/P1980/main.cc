#include <cstdio>

int check(int i, int x)
{
  int c = 0;
  while (i)
  {
    c += i % 10 == x;
    i /= 10;
  }
  return c;
}

int main()
{
  int n, x, ans = 0;
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= n; i++)
  {
    ans += check(i, x);
  }
  printf("%d", ans);
  return 0;
}