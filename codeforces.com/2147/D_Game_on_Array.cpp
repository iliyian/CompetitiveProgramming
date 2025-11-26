// date: 2025-09-24 16:19:27
// tag: ？？真就纯靠猜？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    cnt[x]++;
  }
  int ans = 0, s = 0;
  std::vector<std::array<int, 2>> vec;
  for (auto [k, v] : cnt) {
    s += k * v;
    if (k % 2 == 0) {
      ans += k * v / 2;
    } else {
      vec.push_back({v, k});
    }
  }
  std::ranges::sort(vec, std::greater<>());
  for (int i = 0; i < vec.size(); i++) {
    if (i % 2 == 0) {
      ans += (vec[i][1] + 1) / 2 * vec[i][0];
    } else {
      ans += vec[i][1] / 2 * vec[i][0];
    }
  }
  std::cout << ans << ' ' << s - ans << '\n';
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