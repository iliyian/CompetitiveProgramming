// date: 2024-04-21 12:43:40
// tag: 构造，模拟

#include <bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> b(n + 1);
  int bt = (n - n / m * m);
  int bsiz = (n - 1) / m + 1;
  int l = 1, r = bsiz * bt;
  bitset<N> vis;
  for (int t = 1; t <= k; t++) {
    vis.reset();
    vector<int> big, small;
    if (l < r) {
      for (int i = l; i <= r; i++) {
        vis[i] = true;
      }
    } else {
      for (int i = 1; i <= r; i++) {
        vis[i] = true;
      }
      for (int i = l; i <= n; i++) {
        vis[i] = true;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i]) {
        big.push_back(i);
      } else {
        small.push_back(i);
      }
    }

    int cnt = 0;
    for (auto i : big) {
      if (cnt % bsiz == 0) cout << bsiz << ' ';
      cout << i << ' ';
      cnt++;
      if (cnt % bsiz == 0) cout << '\n';
    }
    cnt = 0;
    for (auto i : small) {
      if (cnt % (n / m) == 0) cout << (n / m) << ' ';
      cout << i << ' ';
      cnt++;
      if (cnt % (n / m) == 0) cout << '\n';
    }

    l = r + 1;
    r = l + bsiz * bt - 1;
    r = (r % n ? r % n : n);
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}