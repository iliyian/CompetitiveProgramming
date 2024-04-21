// date: 2024-04-16 11:29:52
// tag: 贪心，模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  int mp[256];
  mp['U'] = 0, mp['R'] = 1, mp['D'] = 2, mp['L'] = 3;
  int x = 0, y = 0, l = 0, r = 0, u = 0, d = 0;
  for (int i = 0; i < str.size(); i++) {
    int dir = mp[str[i]];
    int xx = x + dx[dir], yy = y + dy[dir];
    if (max(r, yy) + max(-yy, -l) + 1 > m
      || max(-u, -xx) + max(d, xx) + 1 > n) {
      break;
    }
    x = xx, y = yy;
    if (x > d) d = x;
    if (x < u) u = x;
    if (y > r) r = y;
    if (y < l) l = y;
  }
  // cout << 
  int ansx = n - d, ansy = m - r;
  cout << ansx << ' ' << ansy << '\n';
  cerr << format("{} {} {} {}", l, r, u, d) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}