// date: 2024-05-10 14:07:48
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> a(m + 1);
  vector<vector<int>> mx(m + 1, vector<int>(21));
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    mx[i][0] = a[i];
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i + (1 << (j - 1)) <= m; i++) {
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
  }
  int q;
  cin >> q;
  for (int _ = 1; _ <= q; _++) {
    int sx, sy, tx, ty, k;
    cin >> sx >> sy >> tx >> ty >> k;
    if (abs(sx - tx) % k || abs(sy - ty) % k) {
      cout << "NO\n";
      continue;
    }
    if (sy > ty) swap(sy, ty), swap(sx, tx);
    int x = (n - sx) / k * k + sx;
    int q = __lg(ty - sy + 1);
    int max_ = max(mx[sy][q], mx[ty - (1 << q) + 1][q]);
    cout << (max_ < x ? "YES" : "NO") << '\n';
  }

  return 0;
}