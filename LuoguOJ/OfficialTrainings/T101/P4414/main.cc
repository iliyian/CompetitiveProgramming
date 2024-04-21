// 此题用scanf("%s")输入order导致a[0]数值改变

#include <cstdio>
#include <algorithm>

int main()
{
  int a[3];
  scanf("%d %d %d \n", a, a + 1, a + 2);
  std::sort(a, a + 3);
  // printf("a[0] = %d\n", a[0]);
  for (int i = 0; i < 3; i++)
  {
    char ch = getchar();
    // printf("a[%d]=%d\n", i, a[i]);
    // int idx = ch - 'A';
    printf("%d ", a[ch - 'A']);
  }
  return 0;
}