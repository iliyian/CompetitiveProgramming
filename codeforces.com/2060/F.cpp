// date: 2025-01-20 11:35:34
// tag: 计数dp

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

constexpr int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
constexpr int inv(int x) {return qpow(x, mod - 2);}

// m <= 18
int C(int n, int m) {
  if (m > n) return 0;
  int ans = 1;
  for (int i = n; i >= n - m + 1; i--) {
    ans *= i;
    ans %= mod;
  }
  for (int i = 1; i <= m; i++) {
    ans *= inv(i);
    ans %= mod;
  }
  return ans;
}

// S_{n,i}=\sum_{j=1}^{n}{C_{j}^{i}}=C_{n+1}^{i+1}
int S(int n, int i) {
  return C(n + 1, i + 1);
}

constexpr int N = 1e5;

std::vector<std::vector<int>> fac(N + 1);
std::vector<std::vector<int>> f(N + 1, std::vector<int>(18, -1));
// x的长度为len的分解
int getf(int x, int len) {
  if (len == 1) return 1;
  if (f[x][len] != -1) return f[x][len];
  int ans = 0;
  for (int i : fac[x]) {
    if (i != 1 && i != x) {
      ans += getf(x / i, len - 1);
    }
  }
  return f[x][len] = ans;
}

void solve() {
  int k, n;
  std::cin >> k >> n;
  std::cout << n << ' ';
  for (int x = 2; x <= k; x++) {
    int ans = 0;
    for (int len = 1; len <= 17; len++) {
      // std::cout << x << ' ' << len << ' ' << getf(x, len) << '\n';
      ans += getf(x, len) * S(n, len) % mod;
      ans %= mod;
    }
    std::cout << ans << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }

  // std::cout << getf(60, 4) << '\n';
  // return 0;

  // for (int n = 1; n <= 10; n++) {
  // // int n = 9;
  // for (int i = 1; i <= n; i++) {
  //   int ans = 0;
  //   for (int j = 1; j <= n; j++) {
  //     ans += C(j, i);
  //   }
  //   std::cout << ans << ' ';
  // }
  // std::cout << '\n';
  // }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}