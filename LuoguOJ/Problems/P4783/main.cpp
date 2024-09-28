#include <bits/stdc++.h>
#include <cstddef>
#define int long long

constexpr int mod = 998244353;

struct Mat {
  int n, m;
  std::vector<std::vector<int>> a;
  Mat() {}
  Mat(int n, int m) {
    this->n = n, this->m = m; // 这个还有个什么写法来着
    a.assign(n, std::vector<int>(m));
  }
  Mat operator * (const Mat &b) const {
    assert(m == b.n);
    Mat res(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < b.m; j++) {
        for (int k = 0; k < m; k++) {
          res.a[i][j] += a[i][k] * b.a[k][j] % mod;
          res.a[i][j] %= mod;
        }
      }
    }
    return res;
  }
};

Mat qpow(Mat a, int b) {
  assert(a.n == a.m);
  Mat ans(a.n, a.n);
  for (int i = 0; i < a.n; i++) {
    ans.a[i][i] = 1;
  }
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("main.in", "r", stdin);
  int n;
  std::cin >> n;
  Mat a(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a.a[i][j];
    }
  }
  Mat ans = qpow(a, mod - 2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << ans.a[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}