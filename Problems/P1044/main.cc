#include <cstdio>
#include <cstring>
int d[19][19];

int dfs(int x, int y) {
  if (d[x][y]) return d[x][y];
  if (x == 0) return 1;
  if (y > 0) d[x][y] += dfs(x, y-1);
  d[x][y] += dfs(x-1, y+1); 
  return d[x][y];
}

int main() {
  int n;
  memset(d, 0, sizeof(d));
  scanf("%d", &n);
  printf("%d", dfs(n, 0));
  return 0;
}