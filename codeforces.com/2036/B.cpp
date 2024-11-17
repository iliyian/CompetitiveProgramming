#include <bits/stdc++.h>
#define int long long

void solve() {
  std::map<int, int> m;
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int b, c;
    std::cin >> b >> c;
    m[b] += c;
  }
  std::vector<std::pair<int, int>> vec;
  for (auto &[k, v] : m) {
    vec.push_back({v, k});
  }
  std::sort(vec.begin(), vec.end(), std::greater<>());
  int ans = 0;
  for (int i = 0; i < std::min<int>(vec.size(), n); i++) {
    ans += vec[i].first;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}