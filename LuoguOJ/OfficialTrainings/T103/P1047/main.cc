#include <cstdio>
#include <cstring>
int road[100010];

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  memset(road, 0, sizeof(road));
  for (int i = 0; i < m; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    for (int j = l; j <= r; j++)
      road[j] = 1;
  }
  int sum = 0;
  for (int i = 0; i <= n; i++)
    sum += !road[i];
  printf("%d", sum);
  return 0;
}