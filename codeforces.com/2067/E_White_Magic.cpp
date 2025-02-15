// date: 2025-02-13 14:31:49
// tag: 简单的一个observation，显然和0有关，然后按照0的数量分类讨论即可，想得太复杂了，根本没有什么复杂的数据结构

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int c0 = 0;
  std::vector<int> b;
  bool f = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] == 0) {
      if (!f) {
        b.push_back(a[i]);
        f = true;
      }
      c0++;
    } else {
      b.push_back(a[i]);
    }
  }
  if (!c0) {
    std::cout << n << '\n';
    return;
  }
  std::vector<int> mn(b.size());
  mn[0] = b[0];
  for (int i = 1; i < b.size(); i++) {
    mn[i] = std::min(mn[i - 1], b[i]);
  }
  int mex = 0;
  std::set<int> vis;
  for (int i = b.size() - 1; i >= 1; i--) {
    vis.insert(b[i]);
    while (vis.count(mex)) {
      mex++;
    }
    if (mex > mn[i - 1]) {
      std::cout << n - c0 << '\n';
      return;
    }
  }
  std::cout << n - c0 + 1 << '\n';
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