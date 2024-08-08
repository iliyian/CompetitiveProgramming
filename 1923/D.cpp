// date: 2024-08-07 16:38:06
// tag: 二分

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> mn(n + 1), s(n + 1), ans(n + 1, LLONG_MAX);
  std::vector<std::pair<int, int>> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].first < a[i - 1].first || a[i].first < a[i + 1].first) {
      ans[i] = 1;
    }
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 1; i <= n; i++) {
      s[i] = a[i].first + s[i - 1];
    }
    int p = n + 1;
    for (int i = n; i >= 1; i--) {
      if (p == n + 1 || a[p].first != a[i].first) {
        p = i;
      }
      mn[i] = p + 1;
    }
    for (int i = 1; i <= n; i++) {
      auto p = std::upper_bound(s.begin() + 1, s.end(), s[i] + a[i].first) - s.begin();
      if (p != n + 1 && mn[i + 1] != n + 1) {
        ans[a[i].second] = std::min(ans[a[i].second], std::max(p - i, mn[i + 1] - i));
      }
    }
    std::reverse(a.begin() + 1, a.end() - 1);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << (ans[i] == LLONG_MAX ? -1 : ans[i]) << ' ';
  }
  std::cout << '\n';
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