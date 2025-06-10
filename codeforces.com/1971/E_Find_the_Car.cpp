// date: 2025-05-03 22:52:51
// tag: 深刻的教训就是尽可能避免double，在可以都用int的情况下

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, q;
  std::cin >> n >> k >> q;
  std::vector<int> a(k + 1), b(k + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= k; i++) {
    std::cin >> b[i];
  }
  while (q--) {
    int d;
    std::cin >> d;
    auto p = std::upper_bound(a.begin() + 1, a.end(), d) - a.begin() - 1;
    if (a[p] == d) {
      std::cout << b[p] << ' ';
      continue;
    }
    std::cout << b[p] + (d - a[p]) * (b[p + 1] - b[p]) / (a[p + 1] - a[p]) << ' ';
  }
  std::cout << '\n';
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