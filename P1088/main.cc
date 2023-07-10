#include <cstdio>
#include <algorithm>

int main() {
  int fingers[10001];
  int n, m;

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", fingers + i);
  for (int i = 0; i < m; i++)
    std::next_permutation(fingers, fingers + n);
  for (int i = 0; i < n; i++)
    printf("%d ", fingers[i]);

  return 0;
}