// date: 2024-06-14 20:32:22
// tag: 找规律，树，动态规划

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
using namespace std;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  vector<int> in(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    in[x]++, in[y]++;
  }
  vector<int> a(n + 1);
  auto dfs = [&](auto self, int u, int p) -> int {
    int mx = 0;
    for (int v : g[u]) {
      if (v != p) {
        mx = max(mx, self(self, v, u));
      }
    }
    a[u] = mx;
    return mx + 1;
  };
  dfs(dfs, 1, 0);
  int cnt = n;
  for (int i = 1; i <= n; i++) {
    cnt += a[i] % mod;
    cnt %= mod;
  }
  cout << cnt * qpow(2, n - 1) % mod << '\n';
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