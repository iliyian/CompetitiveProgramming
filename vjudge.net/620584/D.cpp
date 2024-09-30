// date: 2024-04-04 21:57:49
// tag: 位运算，分治，动态规划

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

map<int, int> f, g;

int dp(int x) {
  if (f[x]) {
    return f[x];
  }
  if (x == 0) {
    f[x] = 0, g[x] = 1;
    return 0;
  }
  if (x % 2) {
    f[x] = dp(x / 2) % mod * 2 % mod + g[x / 2];
    g[x] = g[x / 2];
  } else {
    f[x] = (dp(x / 2) % mod +
      dp((x - 1) / 2) % mod) % mod * 2;
    g[x] = g[x / 2] + g[(x - 1) / 2];
  }
  return f[x] % mod;
}

void solve() {
  int n, m;
  cin >> n >> m;
  if (m == 1) {
    cout << n % mod << '\n';
  } else if (m >= 3) {
    int t = (n + 1) / 2 % mod;
    if (n % 2) {
      cout << t % mod * t % mod << '\n';
    } else {
      cout << (t + 1) % mod * t % mod << '\n';
    }
  } else {
    cout << dp(n) << '\n';
  }
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