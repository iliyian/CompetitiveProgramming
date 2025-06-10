// date: 2025-03-24 16:43:37
// tag: 比较少见的背包，还是分组背包。其实贪心是好想的，但证伪也应该是容易的，但是继续深入考虑到不同矩形的独立性，和最值，就是分组背包了

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), b(n + 1);
  std::vector<std::vector<std::pair<int, int>>> vec(n + 1);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
    int w = 0, v = 0;
    while (a[i] && b[i]) {
      if (a[i] < b[i]) std::swap(a[i], b[i]);
      if (a[i] == 1 && b[i] == 1) {
        w++, v += 2;
        vec[i].push_back({w, v});
        break;
      }
      w += b[i], v++, a[i]--;
      vec[i].push_back({w, v});
    }
    mx += vec[i].back().second;
  }
  if (mx < k) {
    std::cout << -1 << '\n';
    return;
  }
  std::vector<int> f(k + 301, LLONG_MAX / 3);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = k + 300; j >= 0; j--) {
      for (auto [w, v] : vec[i]) {
        if (j >= v) {
          f[j] = std::min(f[j], f[j - v] + w);
        }
      }
    }
  }
  // std::cerr << mx << ' ' << k << '\n';
  // std::cerr << f[k] << '\n';
  for (int i = k + 299; i >= 0; i--) {
    f[i] = std::min(f[i], f[i + 1]);
    // std::cerr << i << ": " << f[i] << "\n";
  }
  std::cout << (f[k] == LLONG_MAX / 3 ? -1 : f[k]) << '\n';
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