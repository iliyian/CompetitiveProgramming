// date: 2025-05-14 23:34:42
// tag: 典中典之倍数和gcd容斥

#include <bits/stdc++.h>
#define int long long

// constexpr int N = 1e6;
// std::vector<int> fac[N + 1];

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), buc(n + 1), vis(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    buc[a[i]]++;
  }
  i64 ans = n * (n - 1) / 2;
  std::vector<i64> cnt(n + 1);
  std::vector<i64> g(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      if (buc[i]) vis[j] = 1;
      cnt[i] += buc[j];
    }
  }
  for (int i = n; i >= 1; i--) {
    g[i] = cnt[i] * (cnt[i] - 1) / 2;
    for (int j = i + i; j <= n; j += i) {
      g[i] -= g[j];
    }
    ans -= vis[i] * g[i];
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int i = 1; i <= N; i++) {
  //   for (int j = i; j <= N; j += i) {
  //     fac[j].push_back(i);
  //   }
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}