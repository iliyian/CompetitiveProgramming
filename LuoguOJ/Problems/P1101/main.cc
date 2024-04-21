#include <cstdio>

int n;
char rect[101][101];
char ans[101][101];

char target[] = {'y', 'i', 'z', 'h', 'o', 'n', 'g'};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool check(int idx, int x, int y, int d) {
  // printf("idx=%d, x=%d, y=%d, d=%d, rect[%d][%d]=%c\n", idx, x, y, d, x, y, rect[x][y]);
  if (idx == 7) return true;
  if (x < 0 || x >= n || y < 0 || y >= n) return false;
  if (rect[x][y] == target[idx]) {
    int nidx = idx + 1;
    bool res = check(nidx, x+dx[d], y+dy[d], d);
    if (res) ans[x][y] = target[idx];
    return res;
  }
  return false;
}

int main() {
  // freopen("data.out", "w", stdout);

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", &rect[i]);
    for (int j = 0; j < n; j++) {
      ans[i][j] = '*';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (rect[i][j] != 'y') continue;
      for (int k = 0; k < 8; k++) {
        check(0, i, j, k);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", ans[i][j]);
    }
    printf("\n");
  }

  return 0; 
}

/*
8
qyizhong
gydthkjy
nwidghji
orbzsfgz
hhgrhwth
zzzzzozo
iwdfrgng
yyyygggg
*/