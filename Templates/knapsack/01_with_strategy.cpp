// date: 2024-04-26 15:28:53
// tag: 背包，带输出

#include <bits/stdc++.h>
#define N 200000
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;

struct Opt {
  int e, t, p, id;
  bool operator < (const Opt &b) const {
    return e < b.e;
  }
};

array<array<bool, 200>, N + 1> g;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Opt> opts(m + 1);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> opts[i].e >> opts[i].t >> opts[i].p;
    opts[i].id = i;
  }
  sort(opts.begin(), opts.end());
  vector<int> ans;
  auto lo = [&](int x) {
    return lower_bound(opts.begin() + 1, opts.end(), Opt{x, -1, -1}) - opts.begin();
  };
  auto up = [&](int x) {
    return upper_bound(opts.begin() + 1, opts.end(), Opt{x, -1, -1}) - opts.begin();
  };
  int prvt = 0;
  bitset<N + 1> used;
  vector<vector<int>> f(m + 1, vector<int>(200, inf));
  for (int i = 0; i <= m; i++) {
    fill(g[i].begin(), g[i].end(), false);
  }
  for (int e = 1; e <= n; e++) {
    int l = lo(e), r = up(e) - 1, t = a[e] - prvt;
    for (int i = l - 1; i <= r; i++) {
      fill(f[i].begin(), f[i].end(), inf);
      f[i][0] = 0;
    }
    for (int i = l; i <= r; i++) {
      for (int p = 199; p >= 0; p--) {
        f[i][p] = f[i - 1][p];
        if (p >= opts[i].p) {
          int k = f[i - 1][p - opts[i].p] + opts[i].t;
          if (f[i][p] > k) {
            f[i][p] = k;
            g[i][p] = true;
          }
        }
      }
    }
    int p = 100;
    for (int i = 100; i <= 199; i++) {
      if (f[r][i] < f[r][p]) {
        p = i;
      }
    }
    if (f[r][p] > t) {
      cout << -1 << '\n';
      return;
    }
    prvt += f[r][p];
    for (int i = r; i >= l; i--) {
      if (g[i][p]) {
        p -= opts[i].p;
        ans.push_back(opts[i].id);
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
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