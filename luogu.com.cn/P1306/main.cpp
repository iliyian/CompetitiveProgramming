// date: 2024-07-26 15:15:40
// tag: 数学结论，fib，矩阵快速幂

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 1e8;

struct Mat:std::vector<std::vector<int>> {
  int n, m;
  Mat(int n, int m) {
    this->n = n, this->m = m;
    assign(n + 1, std::vector<int>(m + 1));
  }
  Mat operator * (const Mat &b) const {
    assert(m == b.n);
    Mat c(n, b.m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int k = 1; k <= m; k++) {
          c[i][j] += (*this)[i][k] * b[k][j];
          c[i][j] %= mod;
        }
      }
    }
    return c;
  }
};

Mat qpow(Mat a, int b) {
  Mat ans(a.n, a.n);
  for (int i = 1; i <= a.n; i++) {
    ans[i][i] = 1;
  }
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  int g = std::gcd(n, m);
 
  Mat ori(1, 2);
  ori[1][2] = 1;

  Mat P(2, 2);
  P[1][2] = P[2][1] = P[2][2] = 1;

  auto ans = ori * qpow(P, g);
  std::cout << ans[1][1] << '\n';

  return 0;
}