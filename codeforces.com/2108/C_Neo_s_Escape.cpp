#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> b = {0};
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      b.push_back(a[i]);
    }
  }
  b.push_back(0);
  int ans = 0;
  for (int i = 1; i < b.size(); i++) {
    if (b[i] > b[i - 1] && b[i] > b[i + 1]) {
      ans++;
    }
  }
  std::cout << std::max(ans, 1ll) << '\n';
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