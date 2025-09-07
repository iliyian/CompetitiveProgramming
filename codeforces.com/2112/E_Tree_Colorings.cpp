// date: 2025-07-14 12:44:57
// tag: 由特殊到一般的经典范例，首先推导出coloring数量的dp式子，然后推导出根据coloring数量计算最小节点数量的dp式子

#include <bits/stdc++.h>
#define int long long

constexpr int N = 5e5;
std::vector<std::vector<int>> fac(N + 1);
std::vector<int> f(N + 1, LLONG_MAX / 3);

void solve() {
  int n;
  std::cin >> n;
  std::cout << (f[n] == LLONG_MAX / 3 ? -1 : f[n]) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }
  
  f[1] = 1;

  for (int i = 3; i <= N; i += 2) {
    for (int j : fac[i]) {
      if (j != 1) {
        f[i] = std::min(f[i], f[j - 2] + f[i / j]);
      }
    }
  }

  // for (int i = 1; i <= 1000; i += 2) {
  //   std::cerr << i << ' ' << f[i] << '\n';
  // }

  while (t--) {
    solve();
  }

  return 0;
}