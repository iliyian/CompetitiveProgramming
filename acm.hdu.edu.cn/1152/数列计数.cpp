#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), L(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> L[i];
    L[i] = std::min(L[i], a[i]);
  }
  auto calc = [&](auto self, int n, int l, int r, int dep) -> int {
    r = std::min(r, n);
    if (n == 0) return 1;
    if (l == 0 && r == n) {
      // std::cerr << "dep: " << dep << '\n';
      return qpow(2, __builtin_popcountll(n));
    }
    // if (l == r) return (l & n) == l;
    int msb = 62;
    while (n >> msb & 1 ^ 1) msb--;
    if (l >= (1ll << msb)) return self(self, n, l - (1ll << msb), r - (1ll << msb), dep + 1);
    if (r >= (1ll << msb)) return (self(self, n, l, (1ll << msb) - 1, dep + 1) + self(self, n, (1ll << msb), r, dep + 1)) % mod;
    return self(self, n - (1ll << msb), l, r, dep + 1);
  };
  // std::cout << calc(calc, 10, 0, 8) << '\n';
  // return;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= calc(calc, a[i], 0, L[i], 1);
    // std::cerr << a[i] << ' ' << L[i] << ' ' << calc(calc, a[i], 0, L[i], 1) << '\n';
    ans %= mod;
  }
  std::cout << ans << '\n';
}

int C(int n, int m) {
  int ans = 1;
  for (int i = n; i >= n - m + 1; i--) {
    ans *= i;
  }
  for (int i = 1; i <= m; i++) {
    ans /= i;
  }
  return ans % 2;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // int n = 32;
  // std::vector<std::vector<int>> C(n + 1, std::vector<int>(n + 1));
  // for (int i = 1; i <= n; i++) {
  //   C[i][0] = C[i][i] = 1;
  //   for (int j = 1; j < i; j++) {
  //     C[i][j] = C[i - 1][j - 1] ^ C[i - 1][j];
  //   }
  //   int sum = 0;
  //   for (int j = 0; j <= i; j++) {
  //     std::cerr << C[i][j] << ' ';
  //     // if (j != i && j != 0) {
  //       // assert(C[i][j] == ((j & i) == j));
  //     // }
  //     sum += C[i][j];
  //   }
  //   // std::cerr << '\n';
  //   std::cerr << sum << ' ' << (1ll << __builtin_popcountll(i)) << '\n';
  // }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}