// date: 2024-11-28 22:31:12
// tag: 数论，不同质因数个数

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> prv(1e6 + 1);
  for (int i = 1; i <= n; i++) {
    std::vector<int> pri;
    for (int j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        while (a[i] % j == 0) a[i] /= j;
        pri.push_back(j);
      }
    }
    if (a[i] > 1) {
      pri.push_back(a[i]);
    }
    int tot = 0;
    for (int S = 1; S < (1 << pri.size()); S++) {
      int cur = 1;
      for (int j = 0; j < pri.size(); j++) {
        if (S >> j & 1) {
          cur *= pri[j];
        }
      }
      if (i > 1) {
        tot += prv[cur] * (__builtin_popcountll(S) % 2 ? 1 : -1);
        tot = (tot + mod) % mod;
      }
    }
    if (i == 1) tot = 1;
    if (i == n) {
      std::cout << tot << '\n';
      return 0;
    }

    for (int S = 1; S < (1 << pri.size()); S++) {
      int cur = 1;
      for (int j = 0; j < pri.size(); j++) {
        if (S >> j & 1) {
          cur *= pri[j];
        }
      }
      prv[cur] = (prv[cur] + tot) % mod;
    }
  }

  return 0;
}