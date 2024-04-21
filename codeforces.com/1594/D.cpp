// date: 2024-04-14 20:35:28
// tag: 带权并查集

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> pa(n * 2 + 1), siz(n * 2 + 1);
  iota(pa.begin() + 1, pa.end(), 1);
  fill(siz.begin() + 1, siz.begin() + 1 + n, 1);
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  for (int i = 1; i <= m; i++) {
    int x, y;
    string c;
    cin >> x >> y >> c;
    if (c == "imposter") {
      merge(x, y + n);
      merge(y, x + n);
    } else {
      merge(x, y);
      merge(x + n, y + n);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (find(find, i) == find(find, i + n)) {
      cout << -1 << '\n';
      return;
    }
    ans += max(siz[find(find, i)], siz[find(find, i + n)]);
    siz[find(find, i)] = siz[find(find, i + n)] = 0;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}