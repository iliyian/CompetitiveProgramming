#include <bits/stdc++.h>

constexpr int N = 2000;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  std::vector ans(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      int mx = 0, res = 0;
      std::vector<int> mn(r - l + 2);
      mn[r - l + 1] = a[r];
      for (int i = r - 1; i >= l; i--) {
        mn[i - l + 1] = std::min(mn[i - l + 2], a[i]);
      }
      for (int i = l; i < r; i++) {
        mx = std::max(mx, a[i]);
        // if (mx < getmn(i + 1, r)) {
        if (mx < mn[i - l + 2]) {
          res++;
        }
      }
      ans[l][r] = res;
    }
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << ans[l][r] << '\n';
  }
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