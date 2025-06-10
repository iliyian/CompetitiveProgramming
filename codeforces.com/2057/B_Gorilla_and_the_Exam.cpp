#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, K;
  std::cin >> n >> K;
  std::vector<int> a(n + 1);
  std::map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  std::vector<std::pair<int, int>> vec;
  for (auto [k, v] :cnt) {
    vec.push_back({v, k});
  }
  std::sort(vec.begin(), vec.end());
  int ans = cnt.size();
  for (auto [v, k] : vec) {
    if (K < v) break;
    K -= v;
    ans--;
  }
  std::cout << std::max(1ll, ans) << '\n';
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