// date: 2025-04-05 15:17:40
// tag: 矩阵快速幂优化dp

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

struct Mat {
  std::vector<std::vector<int>> a;
  int n, m;
  Mat(int n, int m) : n(n), m(m) {
    a.assign(n + 1, std::vector<int>(m + 1));
  }
  Mat operator * (const Mat &b) {
    Mat ans(n, b.m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= b.n; j++) {
        for (int k = 1; k <= b.m; k++) {
          ans.a[i][j] += a[i][k] * b.a[k][j] % mod;
          ans.a[i][j] %= mod;
        }
      }
    }
    return ans;
  };
};

Mat qpow(Mat a, int b) {
  Mat ans(a.n, a.n);
  for (int i = 1; i <= a.n; i++) {
    ans.a[i][i] = 1;
  }
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int m, n;
  std::cin >> m >> n;
  std::vector<int> s(m + 1), l(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> s[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> l[i];
    s[i] += l[i];
  }
  Mat a(m, m);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      a.a[i][j] = (s[i] * s[j] % mod - l[i] * l[j] % mod + mod) % mod;
    }
  }
  Mat f(1, m);
  f.a[1][1] = 1;
  a = qpow(a, n);
  f = f * a;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += f.a[1][i];
    ans %= mod;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}