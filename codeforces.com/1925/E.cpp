#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> x(m + 1), v(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> v[i];
  }
  vector<int> dis((n + 5) << 2), val((n + 5) << 2);
  auto pushup = [&](int p) {
    dis[p] = dis[lc] + dis[rc];

  };
  auto build = [](auto self, int l, int r, int p) {
    if (l == r) {

      return;
    }
    int mid = (l + r) / 2;
    self(self, l, mid, lc);
    self(self, mid + 1, r, rc);
    pushup(p);
  };
  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l <= s && t <= r) {
      return dis[p]
    }
  };
  build(build, 1, n, 1);
  for (int t = 1; t <= q; t++) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {

    } else {
      cout << query(query, x, y, 1, n, 1) << '\n';
    }
  }
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