#include <bits/stdc++.h>

typedef long long int64;

const int N = 80, mod = 1'000'000'007;

int Power(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1LL * a * a % mod)
    if (k & 1)
      res = 1LL * res * a % mod;
  return res;
}

int Inv(int a) { return Power(a, mod - 2); }

int mat[N + 9][N + 9];

int MatDel(int n) {
  if (!n)
    return 1;
  int res = 1;
  for (int i = 1; i <= n; ++i) {
    int r = i;
    for (; r <= n && !mat[r][i]; ++r)
      ;
    if (r > n)
      return 0;
    if (r != i) {
      for (int j = 1; j <= n; ++j)
        std::swap(mat[i][j], mat[r][j]);
      res = res ? mod - res : 0;
    }
    res = 1LL * res * mat[i][i] % mod;
    int t = Inv(mat[i][i]);
    for (int j = i; j <= n; ++j)
      mat[i][j] = 1LL * mat[i][j] * t % mod;
    for (int j = i + 1; j <= n; ++j) {
      int t = mat[j][i];
      for (int k = i; k <= n; ++k) {
        mat[j][k] = (mat[j][k] - 1LL * t * mat[i][k]) % mod;
        if (mat[j][k] < 0)
          mat[j][k] += mod;
      }
    }
  }
  return res;
}

int inv[N + 9], fac[N + 9], ifac[N + 9];

void start() {
  inv[1] = 1;
  fac[0] = fac[1] = 1;
  ifac[0] = ifac[1] = 1;
  for (int i = 2; i <= N + 3; ++i) {
    inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = 1LL * fac[i - 1] * i % mod;
    ifac[i] = 1LL * ifac[i - 1] * inv[i] % mod;
  }
}

// * (x - v)
void PolyMul(std::vector<int> &a, int v) {
  int n = a.size();
  v = v ? mod - v : 0;
  for (int i = n - 1; i >= 0; --i)
    a[i] = (1LL * a[i] * v + (i ? a[i - 1] : 0)) % mod;
}

// / (x - v)
void PolyDiv(std::vector<int> &a, int v) {
  int n = a.size();
  if (!v) {
    for (int i = 0; i < n; ++i)
      a[i] = i + 1 < n ? a[i + 1] : 0;
    return;
  }
  v = Inv(mod - v);
  for (int i = 0; i < n; ++i)
    a[i] = 1LL * (a[i] + mod - (i ? a[i - 1] : 0)) * v % mod;
}

std::vector<int> Lagrange(const std::vector<int> &val) {
  int n = val.size();
  std::vector<int> res(n), ml(n + 1);
  ml[0] = 1;
  for (int i = 0; i < n; ++i)
    PolyMul(ml, i);
  for (int i = 0; i < n; ++i) {
    PolyDiv(ml, i);
    int c = 1;
    for (int j = 0; j < n; ++j)
      if (j != i)
        c = 1LL * c * (i - j + mod) % mod;
    c = 1LL * val[i] * Inv(c) % mod;
    for (int j = 0; j < n; ++j)
      res[j] = (res[j] + 1LL * c * ml[j]) % mod;
    PolyMul(ml, i);
  }
  return res;
}

int Evaluate(const std::vector<int> &p, int x) {
  int res = 0;
  for (int i = (int)p.size() - 1; i >= 0; --i)
    res = (1LL * res * x + p[i]) % mod;
  return res;
}

void work() {
  int n, cq;
  std::cin >> n >> cq;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; ++i)
    std::cin >> s[i];
  std::vector<int> y(n + 1);
  for (int x = 0; x <= n; ++x) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        mat[i][j] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j < i; ++j) {
        int v = s[i - 1][j - 1] == '0' ? 0 : s[i - 1][j - 1] == '1' ? 1 : x;
        mat[i][j] = mat[j][i] = v ? mod - v : 0;
        mat[i][i] = (mat[i][i] + v) % mod;
        mat[j][j] = (mat[j][j] + v) % mod;
      }
    y[x] = MatDel(n - 1);
    // std::cerr << y[x] << ' ';
  }
  auto p = Lagrange(y);
  for (auto i : p) {
    std::cerr << i << '\n';
  }
  int ans = 0;
  for (int i = 1; i <= cq; ++i) {
    int a, b;
    std::cin >> a >> b;
    int x = 1LL * a * Inv(b) % mod;
    int t = Evaluate(p, x);
    // std::cerr<<t<<'\n';
    ans = (ans + 1LL * i * t) % mod;
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T = 1;
  std::cin >> T;
  start();
  for (; T--;)
    work();
  return 0;
}