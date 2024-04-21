#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;

int dfs(int n, int m) {
  if (n == 1) return 1;
  if (m > n) return 0;
  if (n == m) return 1;
  int ans = 1;
  for (int i = m; i * i <= n; i++) {
    if (n % i == 0) {
      ans += dfs(n / i, i + 1);
      ans %= mod;
      if (i * i != n) {
        ans += dfs(i, n / i + 1);
        ans %= mod;
      }
    }
  }
  return ans % mod;
}

void solve() {
  int n;
  cin >> n;
  cout << dfs(n, 2) - 1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}