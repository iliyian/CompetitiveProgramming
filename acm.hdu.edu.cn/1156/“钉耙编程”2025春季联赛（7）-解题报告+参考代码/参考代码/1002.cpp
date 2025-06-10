#include <algorithm>
#include <bits/stdc++.h>
using poly = std::vector<int>;

namespace Poly {
const int mod = 998244353;
const int N = 50000 * 4 + 5;

int rf[32][N];

void add(int &x, int y) {
  ((x += y) >= mod) && (x -= mod);
}
int fpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = a * 1ll * a % mod)
    if (b & 1)
      res = res * 1ll * a % mod;
  return res;
}
void init(int n) {
  assert(n < N);
  int lg = std::__lg(n);
  static std::vector<bool> bt(32, 0);
  if (bt[lg] == 1)
    return;
  bt[lg] = 1;
  for (int i = 0; i < n; i++)
    rf[lg][i] = (rf[lg][i >> 1] >> 1) + ((i & 1) ? (n >> 1) : 0);
}
void ntt(poly &x, int lim, int op) {
  int lg = std::__lg(lim), gn, g, tmp;
  for (int i = 0; i < lim; i++)
    if (i < rf[lg][i])
      std::swap(x[i], x[rf[lg][i]]);
  for (int len = 2; len <= lim; len <<= 1) {
    int k = (len >> 1);
    gn = fpow(3, (mod - 1) / len);
    for (int i = 0; i < lim; i += len) {
      g = 1;
      for (int j = 0; j < k; j++, g = gn * 1ll * g % mod) {
        tmp = x[i + j + k] * 1ll * g % mod;
        x[i + j + k] = (x[i + j] - tmp + mod) % mod;
        x[i + j] = (x[i + j] + tmp) % mod;
      }
    }
  }
  if (op == -1) {
    reverse(x.begin() + 1, x.begin() + lim);
    int inv = fpow(lim, mod - 2);
    for (int i = 0; i < lim; i++)
      x[i] = x[i] * 1ll * inv % mod;
  }
}
poly multiply(const poly &a, const poly &b) {
  int lim = 1;
  while (lim + 1 < int(a.size() + b.size()))
    lim <<= 1;
  init(lim);
  poly pa = a, pb = b;
  while (pa.size() < lim)
    pa.push_back(0);
  while (pb.size() < lim)
    pb.push_back(0);
  ntt(pa, lim, 1);
  ntt(pb, lim, 1);
  for (int i = 0; i < lim; i++)
    pa[i] = pa[i] * 1ll * pb[i] % mod;
  ntt(pa, lim, -1);
  for (int t = a.size(), i = t; i < pa.size(); i++)
    add(pa[i - t], pa[i]);
  while (int(pa.size()) > int(a.size()))
    pa.pop_back();
  return pa;
}
} // namespace Poly

const int N = 5005;
int n, P, Q;
int a[N], mp[N];

int fpow(int a, int b, int mod) {
  int res = 1;
  for (; b; b >>= 1, a = a * 1ll * a % mod)
    if (b & 1)
      res = res * 1ll * a % mod;
  return res;
}

int getG(int n) {
  static int q[300];
  int i, j, t = 0;
  for (i = 2; i * i < n - 1; i++) {
    if ((n - 1) % i == 0)
      q[t++] = i, q[t++] = (n - 1) / i;
  }
  for (i = 2;; i++) {
    for (j = 0; j < t; j++)
      if (fpow(i, q[j], n) == 1)
        break;
    if (j == t)
      return i;
  }
  return -1;
}

poly poly_pow(const poly &a, int b, const int p) {
  if (b == 1)
    return a;
  auto r = poly_pow(a, b >> 1, p);
  r = Poly::multiply(r, r);
  if (b & 1) {
    r = Poly::multiply(a, r);
  }
  return r;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  std::cin >> T;
  while (T--) {
    std::cin >> n >> Q >> P;
    for (int i = 1; i <= n; i++)
      std::cin >> a[i], assert(a[i] >= 1 && a[i] < P);
    int g = getG(P);
    for (int i = 1, r = 1; i < P; i++) {
      r = r * g % P;
      mp[r] = (i == P - 1) ? 0 : i;
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(P - 1, 0));
    dp[0][mp[1]] = 1;
    for (int i = 1; i <= n; i++) {
      int r = mp[a[i]];
      for (int j = 0; j < P - 1; j++) {
        int k = (j + r >= P - 1) ? (j + r - P + 1) : (j + r);
        Poly::add(dp[i][k], dp[i - 1][j]);
        Poly::add(dp[i][j], dp[i - 1][j]);
      }
    }

    int rem = Q % n;
    poly a(P - 1, 0), b(P - 1, 0);

    for (int i = 0; i < P - 1; i++) {
      a[i] = dp[n][i];
      b[i] = dp[rem][i];
    }
    
    a = poly_pow(a, Q / n, P - 1);
    a = Poly::multiply(a, b);

    int ans = 0;
    for (int i = 1; i < P; i++) {
      ans ^= a[mp[i]];
    }
    std::cout << ans << '\n';
  }
  return 0;
}