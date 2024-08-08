// date: 2024-08-07 15:13:39
// tag: 矩阵快速幂优化概率dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 1e9 + 7;

struct Mat {
  int n, m;
  std::vector<std::vector<int>> a;
  Mat(int n, int m) {
    this->n = n, this->m = m;
    a.assign(n, std::vector<int>(m));
  }
  Mat operator * (const Mat &b) const {
    Mat c(n, b.m);
    for (int k = 0; k < m; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < b.m; j++) {
          c.a[i][j] += a[i][k] * b.a[k][j] % mod;
          c.a[i][j] %= mod;
        }
      }
    }
    return c;
  }
};

Mat qpow(Mat a, int b) {
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

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[i] = cnt[i - 1] + (a[i] == 0);
  }
  int m = cnt[n];
  Mat f(m + 1, 1);
  f.a[cnt[m]][0] = 1;
  Mat mat(m + 1, m + 1);
  for (int i = 0; i <= m; i++) {
    int t = n * (n - 1) / 2;
    if (i < m) {
      mat.a[i + 1][i] = (m - i) * (m - i);
    }
    if (i > 0) {
      mat.a[i - 1][i] = i * (n - m - (m - i));
    }
    mat.a[i][i] = t - i * (n - m - (m - i)) - (m - i) * (m - i);
    // mat.a[i][i] = std::max(mat.a[i][i], 0ll);
  }
  mat = qpow(mat, k);
  f = mat * f;
  int sum = qpow(n * (n - 1) / 2, k);
  int ans = f.a[m][0] * inv(sum) % mod;
  std::cout << ans << '\n';

  return 0;
}