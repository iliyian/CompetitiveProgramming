#include <cstdio>
#include <cstring>

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  int q, w, x, h;
  int cube[21][21][21];
  scanf("%d %d %d %d", &w, &x, &h, &q);
  for (int i = 1; i <= w; i++)
    for (int j = 1; j <= x; j++)
      for (int k = 1; k <= h; k++)
        cube[i][j][k] = 0;

  while (q--) {
    int x1, y1, z1, x2, y2, z2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
    for (int i = x1; i <= x2; i++)
      for (int j = y1; j <= y2; j++)
        for (int k = z1; k <= z2; k++)
          cube[i][j][k] = 1;
  }
  
  int count = 0;

  for (int i = 1; i <= w; i++)
    for (int j = 1; j <= x; j++)
      for (int k = 1; k <= h; k++)
        count += !cube[i][j][k];
        
  printf("%d", count);
  return 0;
}