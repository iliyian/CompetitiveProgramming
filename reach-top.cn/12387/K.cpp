#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> a(n);
  for (auto &i : a) {
    int x, y;
    std::cin >> x >> y;
    i.first = -y, i.second = -x;
  }
  std::sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans += -a[i].second;
  }
  std::cout << ans << "\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}