#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> f(n + 10);
  auto dfs = [&](auto self, int sum) -> int {
    if (sum <= 2) return 1;
    if (f[sum]) return f[sum] % mod;
    int ans = 1;
    for (int t = 3; t <= sum; t++) {
      for (int i = 1; i <= t / 2; i++) {
        ans = (ans + self(self, i) * self(self, t - i) % mod)
           % mod;
      }
    }
    return f[sum] = ans;
  };
  cout << dfs(dfs, n) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}