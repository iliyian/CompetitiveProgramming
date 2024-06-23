// date: 2024-06-22 23:36:05
// tag: 哈希，暴力，字典树

#include <bits/stdc++.h>
#define int long long
using namespace std;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1)), pos(n + 1, vector<int>(m + 1));
  unordered_set<int> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      pos[i][a[i][j]] = j;
    }
    int h = 0;
    for (int j = 1; j <= m; j++) {
      h = h + j * qpow(10, m - pos[i][j]);
      s.insert(h);
      // cout << h << ' ';
    }
    // cout << '\n';
  }
  for (int i = 1; i <= n; i++) {
    int h = 0, ans = 0;
    for (int j = 1; j <= m; j++) {
      h = h + j * qpow(10, m - a[i][j]);
      if (s.count(h)) {
        ans = j;
      }
      // cout << h << ' ';
    }
    cout << ans << ' ';
  }
  cout << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}