#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, c;
  std::cin >> n >> k >> c;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  std::vector<int> l, r;
  for (int i = 1; i <= k; i++) {
    ans += a[i];
    l.push_back(-a[i] - (k - i + 1) * c);
  }
  for (int i = k + 1; i <= n; i++) {
    r.push_back(a[i] - (i - k) * c);
  }
  std::ranges::sort(l, std::greater<>());
  std::ranges::sort(r, std::greater<>());
  // for (int i : l) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  // for (int i : r) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  for (int i = 0; i < std::min(l.size(), r.size()); i++) {
    if (l[i] + r[i] + c >= 0) {
      ans += l[i] + r[i] + c;
    }
  }
  std::cout << ans << '\n';
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