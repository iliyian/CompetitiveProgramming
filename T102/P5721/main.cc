#include <cstdio>

int main()
{
  int n;
  scanf("%d", &n);
  int c = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = n - i; j >= 1; j--)
    {
      printf("%02d", ++c);
    }
    printf("\n");
  }
  return 0;
}