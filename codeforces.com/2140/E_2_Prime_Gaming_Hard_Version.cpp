// date: 2025-09-17 20:05:46
// tag: 我愿称 $x=\sum_{i=1}{[x\ge i]}$为世界上最伟大的公式

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

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
  int n, m;
  std::cin >> n >> m;
  int c;
  std::cin >> c;
  std::vector<int> b(n);
  for (int i = 0; i < c; i++) {
    int x;
    std::cin >> x;
    x--;
    b[x] = 1;
  }
  if (m == 1) {
    std::cout << 1 << '\n';
    return;
  }
  std::vector<int> f(2);
  f[0] = 1;
  f[1] = 2;
  int s = 0;
  bool flag = n & 1 ^ 1;
  for (int i = 2; i <= n; i++) {
    std::vector<int> nf(1ll << i);
    for (int j = 0; j < (1ll << i); j++) {
      for (int k = 0; k < i; k++) {
        if (b[k]) {
          int t = j & ((1ll << k) - 1);
          t |= j >> (k + 1) << k;
          nf[j] |= f[t];
        }
      }
    }
    for (int j = 0; j < (1ll << i); j++) {
      if (nf[j] == 3) {
        if (flag) {
          nf[j] = 2;
        } else {
          nf[j] = 1;
        }
      }
    }
    f = nf;
    flag ^= 1;
  }
  std::vector<int> cnt(1ll << n);
  for (int i = 0; i < (1ll << n); i++) {
    cnt[__builtin_popcountll(i)] += f[i] == 2;
  }
  int ans = 0;
  for (int k = 1; k <= m; k++) {
    for (int i = 0; i <= n; i++) {
      ans += qpow(m - k + 1, i) * qpow(k - 1, n - i) % mod * cnt[i] % mod;
      ans %= mod;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}