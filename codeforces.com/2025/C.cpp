#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  std::map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  std::vector<std::pair<int, int>> vec;
  for (auto [k, v] : cnt) {
    vec.push_back({k, v});
  }
  int ans = 0, cur = 0, l = 0, r = 0;
  cur = vec[l].second;
  while (l < vec.size()) {
    while (r < l) cur += vec[++r].second;
    while (r + 1 < vec.size() &&
           vec[r + 1].first - vec[r].first == 1 &&
           r + 1 - l + 1 <= k) {
      cur += vec[++r].second;
    }
    ans = std::max(ans, cur);
    cur -= vec[l++].second;
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