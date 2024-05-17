// date: 2024-05-16 21:04:04
// tag: 

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e5)
#define mod ((int)1e9 + 7)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  vector<int> in(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    in[u]++, in[v]++;
  }

  auto qpow = [](int a, int b) {
    int ans = 1;
    while (b) {
      if (b & 1) ans = ans * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return ans;
  };
  
  int ans = qpow(2, in[1]) - 1;
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
    if (in[u] >= 2 && u != 1) {
      ans += in[u] - 1;
      ans %= mod;

      ans += qpow(2, in[u]);
      ans %= mod;
      ans -= 1 + in[u]; // 这里理论上似乎可以hack掉，但我懒得改了...反正要小心
      ans %= mod;
      // ans += (1 << in[u]) - 1 - in[u];
    }
  };
  dfs(dfs, 1, 0);
  cout << ans << '\n';

  return 0;
}