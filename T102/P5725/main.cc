#include <cstdio>

int main()
{
  int n, c = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      printf("%02d", ++c);
    printf("\n");
  }
  printf("\n");
  c = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < n - i; j++)
      printf("  ");
    for (int j = 0; j < i; j++)
      printf("%02d", ++c);
    printf("\n");
  }
  return 0;
}