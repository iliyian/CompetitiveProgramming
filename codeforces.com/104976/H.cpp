// date: 2024-05-22 19:55:45
// tag: 基环树，概率 

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
#define N ((int)5e5)
using namespace std;

vector<int> fac(N + 1), inv(N + 1), invfac(N + 1);

int C(int n, int m) {
  return fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), w(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  vector<int> p(n + 1, -1), dep(n + 1);
  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] < a[b[i]]) {
      p[i] = 1;
    } else if (a[i] >= a[b[i]] + w[b[i]] || i == b[i]) {
      p[i] = 0;
    } else {
      g[b[i]].push_back(i);
    }
  }
  auto dfs = [&](auto self, int u) -> void {
    for (int v : g[u]) {
      dep[v] = dep[u] + 1;
      self(self, v);
    }
  };
  for (int i = 1; i <= n; i++) {
    if (p[i] == 1) {
      dep[i] = 1;
      dfs(dfs, i);
    }
  }
  vector<int> ans(n + 1);
  // for (int i = 1; i <= n; i++) {
  //   cerr << dep[i] << " \n"[i == n];
  // }
  // for (int i = 1; i <= n; i++) {
  //   cerr << p[i] << " \n"[i == n];
  // }
  for (int i = 1; i <= n; i++) {
    if (p[i] == 0 || p[i] == -1 && dep[i] == 0) {
      ans[i] = a[i];
    } else if (p[i] == 1) {
      ans[i] = (a[i] + w[i]) % mod;
    } else {
      ans[i] = (a[i] + w[i] * invfac[dep[i]] % mod) % mod;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  inv[1] = fac[0] = fac[1] = invfac[0] = invfac[1] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = i * fac[i - 1] % mod;
  }
  for (int i = 2; i <= N; i++) {
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}