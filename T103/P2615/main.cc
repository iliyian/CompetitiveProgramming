#include <cstdio>
int n, rect[40][40];

void step(int &x, int &y) {
  // printf("x=%d, y=%d, n-1=%d\n", x, y, n-1);
  if (!x && y != n-1) x = n-1, y++;
  else if (x && y == n-1) y = 0, x--;
  else if (!x && y == n-1) x = 1;
  else x--, y++;

  if (rect[x][y]) x += 2, y--;
}

int main() {
  // freopen("data.out", "w", stdout);

  scanf("%d", &n);
  int x = 0, y = n / 2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      rect[i][j] = 0;
  
  int num = 1;
  while (num <= n * n) {
    rect[x][y] = num++;
    step(x, y);
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", rect[i][j]);
    printf("\n");
  }
  return 0;
}