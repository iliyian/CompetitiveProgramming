#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::array<std::vector<int>, 4> g;
  std::vector<int> ans;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    g[a[i] % 4].push_back(i);
  }
  auto pop = [&](int x) {
    ans.push_back(g[x].back());
    g[x].pop_back();
  };
  while (!g[0].empty()) {
    pop(0);
  }
  while (g[1].size() >= 1 && g[3].size() >= 1) {
    pop(3);
    pop(1);
  }
  if (!g[1].empty() || !g[3].empty()) {
    if (!g[1].empty()) {
      if (g[1].size() > g[2].size() * 2) {
        std::cout << -1 << '\n';
        return;
      }
      while (!g[1].empty()) {
        pop(2);
        pop(1);
        pop(1);
      }
      while (!g[2].empty()) {
        pop(2);
      }
    } else {
      if (g[3].size() > g[2].size() * 2) {
        std::cout << -1 << '\n';
        return;
      }
      while (!g[3].empty()) {
        pop(3);
        pop(3);
        pop(2);
      }
      while (!g[2].empty()) {
        pop(2);
      }
    }
  } else {
    while (!g[2].empty()) {
      pop(2);
    }
  }
  for (auto i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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