// date: 2025-03-26 15:07:54
// tag: 单调栈计算贡献，然后弄个后缀max就行的板子题

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), l(n + 1), r(n + 1);
  std::stack<int> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    l[i] = (s.empty() ? 0 : s.top()) + 1;
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    r[i] = (s.empty() ? n + 1 : s.top()) - 1;
    s.push(i);
  }
  std::vector<int> ans(n + 2);
  for (int i = 1; i <= n; i++) {
    int len = r[i] - l[i] + 1;
    // std::cerr << l[i] << ' ' << r[i] << '\n';
    ans[len] = std::max(ans[len], a[i]);
  }
  for (int i = n; i >= 1; i--) {
    ans[i] = std::max(ans[i], ans[i + 1]);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
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