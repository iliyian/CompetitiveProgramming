#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  constexpr int N = 1e6;
  std::vector<int> ans(N + 1);
  ans[1] = 1;
  for (int i = 2; i <= a[n]; i++) {
    auto p = std::upper_bound(a.begin() + 1, a.end(), i) - a.begin() - 1;
    ans[i] = i / a[p] + ans[i % a[p]];
    // std::cerr << i << ": " << ans[i] << '\n';
  }
  std::vector<int> rv(N + 1);
  for (int i = 1; i <= a[n]; i++) {
    rv[ans[i]]++;
  }
  for (int i = 1; i <= N; i++) {
    rv[i] += rv[i - 1];
  }
  while (m--) {
    int x;
    std::cin >> x;
    std::cout << rv[std::min(N, x)] << ' ';
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