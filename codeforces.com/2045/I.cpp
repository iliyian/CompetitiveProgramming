// date: 2024-12-12 10:30:26
// tag: 区间颜色数，扫描线，计算贡献，字符串相关

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) -> void {for (int i = x; i <= n; i += i & -i) d[i] += c;};
  auto query = [&](int x) -> int {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += d[i];
    }
    return ans;
  };
  int ans = 0, dif = 0;
  std::vector<int> pos(m + 1);
  for (int i = 1; i <= n; i++) {
    // std::Cout <<
    int t = dif - query(pos[a[i]]);
    // std::cout << t << ' ' << pos[a[i]] << '\n';
    if (!pos[a[i]]) {
      ans += t * 2;
      dif++;
    } else {
      ans += t;
    }
    // std::cout << ans << '\n';

    if (pos[a[i]]) { 
      add(pos[a[i]], -1);
    }
    pos[a[i]] = i;
    add(pos[a[i]], 1);
  }
  // std::cout << ans << '\n';
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    if (pos[i]) {
      cnt++;
      // ans++;
    }
  }
  ans += cnt * (m - cnt);
  std::cout << ans << '\n';
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