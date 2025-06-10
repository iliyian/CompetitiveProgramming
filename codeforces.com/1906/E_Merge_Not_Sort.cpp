// date: 2025-04-08 19:35:31
// tag: 归并排序，可行性01背包方案构造

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n * 2 + 1);
  int mx = 0, len = 0;
  std::vector<int> vec;
  std::vector<int> w(n * 2 + 1);
  for (int i = 1; i <= n * 2; i++) {
    std::cin >> a[i];
    if (a[i] > mx && mx != 0) {
      mx = a[i];
      vec.push_back(i - 1);
      w[i - 1] = len;
      len = 0;
    }
    mx = std::max(mx, a[i]);
    len++;
  }
  w[n * 2] = len;
  vec.push_back(n * 2);
  std::vector<int> f(n + 1), g(n + 1);
  f[0] = 1;
  for (auto id : vec) {
    // std::cerr << w[id] << ' ' << id << '\n';
    for (int i = n; i >= w[id]; i--) {
      if (f[i - w[id]]) {
        // std::cerr << id << ' ' << i << '\n';
        if (!f[i]) {
          f[i] = 1;
          g[i] = id;
        }
      }
    }
  }
  if (!f[n]) {
    std::cout << -1 << '\n';
    return;
  }
  std::vector<int> ans(n * 2 + 1);
  int cur = n;
  while (cur > 0) {
    // std::cerr << cur << ' ' << g[cur] << '\n';
    for (int i = 1; i <= w[g[cur]]; i++) {
      ans[a[g[cur] - i + 1]] = 1;
    }
    cur -= w[g[cur]];
  }
  for (int i = 1; i <= n * 2; i++) {
    if (ans[a[i]]) {
      std::cout << a[i] << ' ';
    }
  }
  std::cout << '\n';
  for (int i = 1; i <= n * 2; i++) {
    if (!ans[a[i]]) {
      std::cout << a[i] << ' ';
    }
  }
  std::cout << '\n';
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