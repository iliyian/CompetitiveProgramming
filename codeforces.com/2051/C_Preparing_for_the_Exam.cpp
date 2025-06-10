#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(m + 1), q(k + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= k; i++) {
    std::cin >> q[i];
  }
  if (k == n) {
    for (int i = 1; i <= m; i++) {
      std::cout << 1;
    }
    std::cout << '\n';
    return;
  }
  if (k < n - 1) {
    for (int i = 1; i <= m; i++) {
      std::cout << 0;
    }
    std::cout << '\n';
    return;
  }
  int r = 1;
  while (r <= k && r == q[r]) r++;
  for (int i = 1; i <= m; i++) {
    std::cout << (r == a[i]);
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