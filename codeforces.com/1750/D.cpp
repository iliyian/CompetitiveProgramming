// date: 2024-05-27 18:04:45
// tag: 容斥原理

#include <bits/stdc++.h>
#define mod 998244353
#define N ((int)2e5)
#define int long long

using namespace std;

vector<int> pri;
bitset<N + 1> vis;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] % a[i]) {
      cout << 0 << '\n';
      return;
    }
    int x = a[i - 1] / a[i], cnt = 0;
    vector<int> fac;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        fac.push_back(j);
        while (x % j == 0) x /= j;
      }
    }
    if (x != 1) fac.push_back(x);
    int lim = m / a[i];
    for (int S = 0; S < (1ll << fac.size()); S++) { // < 2**10
      int t = 1;
      for (int j = 0; j < fac.size(); j++) {
        if (S >> j & 1) {
          t = t * fac[j];
        }
      }
      cnt += (__builtin_popcountll(S) & 1 ^ 1 ? 1 : -1) * (lim / t) % mod;
      cnt = (cnt % mod + mod) % mod;
    }
    ans = ans * cnt % mod;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}