#include <cstdio>

int main()
{
  int n, k;
  double asum = 0, bsum = 0;
  int ac = 0, bc = 0;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++)
  {
    if (!(i % k))
      asum += i, ac++;
    else
      bsum += i, bc++;
  }
  printf("%.1lf %.1lf", asum / ac, bsum / bc);
  return 0;
}