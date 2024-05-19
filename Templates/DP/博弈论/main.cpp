// date: 2024-05-19 20:27:49
// tag: 博弈论dp，概率

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

int inv(int x) {
  return qpow(x, mod - 2);
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> f(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    f[i][0] = 0;
    for (int j = 1; j <= min(i - 1, m); j++) {
      f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod * inv(2) % mod;
    }
    if (i <= m) {
      f[i][i] = i * k % mod;
    }
  }
  cout << f[n][m] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D1.in", "r", stdin);
  freopen("D1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}