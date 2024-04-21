// 分而治之然后合并

#include <bits/stdc++.h>
using namespace std;

int n, k;

int a[1024];

void solve(int x, int y, int rx, int ry, int len) {
  if (len == 1) return;
  int lenn = len >> 1;
  if (x - rx < lenn && y - ry < lenn) {
    cout << rx + lenn + 1<< ' ' << ry + lenn + 1 << ' ' << 1 << '\n';
    solve(x, y, rx, ry, lenn);
    solve(rx + lenn, ry + lenn - 1, rx + lenn, ry, lenn);
    solve(rx + lenn - 1, ry + lenn, rx, ry + lenn, lenn);
    solve(rx + lenn, ry + lenn, rx + lenn, ry + lenn, lenn);
  } else if (x - rx < lenn && y - ry >= lenn) {
    cout << rx + lenn + 1 << ' ' << ry + lenn - 1 + 1<< ' ' << 2 << '\n';
    solve(x, y, rx, ry + lenn, lenn);
    solve(rx + lenn - 1, ry + lenn - 1, rx, ry, lenn);
    solve(rx + lenn, ry + lenn - 1, rx + lenn, ry, lenn);
    solve(rx + lenn, ry + lenn, rx + lenn, ry + lenn, lenn);
  } else if (x - rx >= lenn && y - ry < lenn) {
    cout << rx + lenn - 1 + 1<< ' ' << ry + lenn + 1<< ' ' << 3 << '\n';
    solve(x, y, rx + lenn, ry, lenn);
    solve(rx + lenn - 1, ry + lenn - 1, rx, ry, lenn);
    solve(rx + lenn - 1, ry + lenn, rx, ry + lenn, lenn);
    solve(rx + lenn, ry + lenn, rx + lenn, ry + lenn, lenn);
  } else if (x - rx >= lenn && y - ry >= lenn) {
    cout << rx + lenn - 1 + 1 << ' ' << ry + lenn - 1 + 1 << ' ' << 4 << '\n';
    solve(x, y, rx + lenn, ry + lenn, lenn);
    solve(rx + lenn - 1, ry + lenn - 1, rx, ry, lenn);
    solve(rx + lenn - 1, ry + lenn, rx, ry + lenn, lenn);
    solve(rx + lenn, ry + lenn - 1, rx + lenn, ry, lenn);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int x, y;
  cin >> k >> x >> y;
  n = 1 << k;
  x--, y--;
  solve(x, y, 0, 0, n);
  return 0;
}