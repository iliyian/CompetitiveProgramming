#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> vec = {INT_MIN};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int t = a[i];
    for (int j = 2; j * j <= t; j++) {
      if (t % j == 0) {
        vec.push_back(j);
        while (t % j == 0) t /= j;
      }
    }
    if (t > 1) {
      vec.push_back(t);
    }
  }
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  auto id = [&](int x) -> int {
    return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };
  int len = vec.size() - 1;
  std::vector<std::vector<int>> g(len + 1);
  for (int i = 1; i <= n; i++) {
    int t = a[i];
    for (int j = 2; j * j <= t; j++) {
      if (t % j == 0) {
        g[id(j)].push_back(i);
        while (t % j == 0) t /= j;
      }
    }
    if (t > 1) {
      g[id(t)].push_back(i);
    }
  }
  // std::cout << len << '\n';
  int mi = 0, mj = 0, mx = n;
  for (int i = 1; i <= len; i++) {
    for (int j = i + 1; j <= len; j++) {
      if (g[i].size() + g[j].size() > mx) {
        mx = g[i].size() + g[j].size();
        mi = i, mj = j;
      }
    }
  }
  if (mi == 0 || mj == 0) {
    std::cout << -1 << '\n';
    return;
  }
  // std::cout << vec[mi] << ' ' << vec[mj] << ' ' << mx << '\n';
  std::cout << g[mi].size() << ' ' << g[mj].size() << '\n';
  std::vector<int> ans1, ans2, ans3;
  for (auto i : g[mi]) {
    auto p = std::lower_bound(g[mj].begin(), g[mj].end(), i);
    if (p == g[mj].end() || *p != i) {
      ans1.push_back(i);
    } else {
      ans3.push_back(i);
    }
  }
  for (auto i : g[mj]) {
    auto p = std::lower_bound(g[mi].begin(), g[mi].end(), i);
    if (p == g[mi].end() || *p != i) {
      ans2.push_back(i);
    }
  }
  std::cout << ans1.size() << ' ' << ans2.size() << ' ' << ans3.size() << '\n';
  while (!ans3.empty()) {
    (ans1.size() < ans2.size() ? ans1 : ans2).push_back(ans3.back());
    ans3.pop_back();
  }
  std::vector<int> ans(n + 1);
  for (auto i : ans2) {
    ans[i] = 1;
  }
  int g1 = 0, g2 = 0;
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] + 1 << ' ';
    if (ans[i]) {
      g2 = std::gcd(g2, a[i]);
    } else {
      g1 = std::gcd(g1, a[i]);
    }
  }
  std::cout << '\n';
  // std::cout << g1 << ' ' << g2 << '\n';
  assert(g1 > 1 && g2 > 1);
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