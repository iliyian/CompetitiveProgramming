#include <bits/stdc++.h>
using namespace std;

int a[51][51];

const char cub[6][8] = {
  "..+---+",
  "./   /|",
  "+---+ |",
  "|   | +",
  "|   |/.",
  "+---+.."
};

// unordered_map<int, unordered_map<int, char>> ans;
char ans[1000][1000];

int maxx = -1, maxy = -1, minx = 1 << 30, miny = 1 << 30;

void print() {
  for (int i = minx; i < maxx; i++) {
    for (int j = miny; j < maxy; j++) {
      if (!ans[i][j])
        cout << '.';
      else cout << ans[i][j];
    }
    cout << '\n';
  }
  cout << '\n';
}

void sets(int x, int y) {
  minx = min(minx, x - 3);
  miny = min(miny, y - 2);
  maxx = max(maxx, x + 3);
  maxy = max(maxy, y + 5);
  for (int i = x - 3; i < x + 3; i++)
    for (int j = y - 2; j < y + 5; j++) {
      int t = cub[i - (x - 3)][j - (y - 2)];
      if (t == '.' && ans[i][j]) continue;
      ans[i][j] = cub[i - (x - 3)][j - (y - 2)]; 
    }
  // print();
}

void up(int &x, int &y, int t) {
  x -= t * 3;
}

void right(int &x, int &y, int t) {
  y += t * 4;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int m, n, maxh = -1;
  cin >> m >> n;
  for (int i = 0; i < 1000; i++)
    memset(ans[i], 0, sizeof(ans[i]));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j], maxh = max(maxh, a[i][j]);
  int x = 3 * maxh, y = m * 2;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int t = a[i][j];
      for (int k = 0; k < t; k++) {
        sets(x, y);
        up(x, y, 1);
      }
      up(x, y, -a[i][j]);
      right(x, y, 1);
    }
    right(x, y, -n);
    x += 2, y -= 2;
  }
  print();
  return 0;
}