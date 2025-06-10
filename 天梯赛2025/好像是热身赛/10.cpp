#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a;
  auto get = [&](const std::string &str) {
    return stoll(str.substr(0, 2)) * 3600 + stoll(str.substr(3, 2)) * 60 + stoll(str.substr(6, 2));
  };
  for (int i = 1; i <= n; i++) {
    std::string l, r;
    std::cin >> l >> r;
    int lt = get(l), rt = get(r);
    rt--;
    a.push_back({rt, lt});
  }
  std::sort(a.begin(), a.end());
  int prvr = -1, ans = 0;
  for (auto [r, l] : a) {
    // std::cerr << l << ' ' << r << '\n';
    if (l > prvr) {
      prvr = r;
      ans++;
      // std::cerr << "! " << l << ' ' << r << '\n';
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