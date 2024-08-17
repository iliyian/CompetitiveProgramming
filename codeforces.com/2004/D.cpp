// date: 2024-08-16 12:31:39
// tag: 模拟

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::pair<char, char>> col(n + 1);
  std::map<std::pair<char, char>, std::vector<int>> m;
  auto id = [&](char ch) {
    if (ch == 'R') return 0;
    if (ch == 'B') return 1;
    if (ch == 'G') return 2;
    if (ch == 'Y') return 3;
    return -1;
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> col[i].first >> col[i].second;
    if (id(col[i].first) > id(col[i].second)) {
      std::swap(col[i].first, col[i].second);
    }
    m[col[i]].push_back(i);
  }
  auto check = [&](int x, int y) {
    return col[x].first == col[y].first || col[x].first == col[y].second ||
           col[x].second == col[y].first || col[x].second == col[y].second;
  };
  auto work = [&](std::pair<char, char> pr, int x, int y) -> int {
    if (id(pr.first) > id(pr.second)) std::swap(pr.first, pr.second);
    auto &v = m[pr];
    if (v.empty()) return INT_MAX;
    auto p = std::upper_bound(v.begin(), v.end(), x);
    int ans = INT_MAX;
    if (p != v.end()) {
      if (*p < y) ans = y - x;
      else ans = *p - y + *p - x;
    }
    p = std::lower_bound(v.begin(), v.end(), x);
    if (p != v.begin()) {
      p = std::prev(p);
      ans = std::min(ans, x - *p + y - *p);
    }
    return ans;
  };
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    if (x > y)
      std::swap(x, y);
    if (check(x, y)) {
      std::cout << std::abs(x - y) << '\n';
      continue;
    }
    int ans = std::min({
      work({col[x].first, col[y].first}, x, y),
      work({col[x].first, col[y].second}, x, y),
      work({col[x].second, col[y].first}, x, y),
      work({col[x].second, col[y].second}, x, y),
    });
    std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}