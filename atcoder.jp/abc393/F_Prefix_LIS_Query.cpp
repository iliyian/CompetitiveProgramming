#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::array<int, 3>> ask(q + 1);
  for (int i = 1; i <= q; i++) {
    int r, x;
    std::cin >> r >> x;
    ask[i] = {r, x, i};
  }
  std::sort(ask.begin() + 1, ask.end());
  std::vector<int> ans(q + 1), b;
  int R = 0;
  for (int i = 1; i <= q; i++) {
    auto [r, x, id] = ask[i];
    while (R < r) {
      ++R;
      if (b.empty() || a[R] > b.back()) {
        b.push_back(a[R]);
      } else {
        *std::lower_bound(b.begin(), b.end(), a[R]) = a[R];
      }
    }
    // std::cerr << b.size() << '\n';
    ans[id] = std::upper_bound(b.begin(), b.end(), x) - b.begin();
  }
  for (int i = 1; i <= q; i++) {
    std::cout << ans[i] << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}