#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto check = [&](int mid) -> bool {
    int cur = 0, t = 0;
    std::vector<int> vis(mid + 1);
    std::vector<int> vec;
    // std::set<int> s;
    for (int i = 1; i <= n; i++) {
      // s.insert(a[i]);
      if (a[i] <= mid) {
        vis[a[i]] = 1;
        vec.push_back(a[i]);
      }
      // while (s.count(cur)) {
      while (vis[cur]) {
        cur++;
        if (cur == mid + 1) {
          cur = 0;
          t++;
          if (t >= k) {
            return true;
          }
          // s.clear();
          for (auto j : vec) {
            vis[j] = false;
          }
          vec.clear();
          break;
        }
      }
    }
    return t >= k;
  };
  int l = 0, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans + 1 << '\n';
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