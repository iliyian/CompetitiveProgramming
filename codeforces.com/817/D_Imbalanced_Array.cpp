// date: 2025-03-26 15:24:05
// tag: 又是单调栈算贡献，但这次和区间计数有关，因此要处理相同值的情况，具体也就是一侧有等号，一侧无等号，还是很神奇和方便的

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::stack<int> s;
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    l[i] = (s.empty() ? 0 : s.top()) + 1;
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] > a[i]) {
      s.pop();
    }
    r[i] = (s.empty() ? n + 1 : s.top()) - 1;
    s.push(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans -= (r[i] - i + 1) * (i - l[i] + 1) * a[i];
    // std::cerr << l[i] << ' ' << r[i] << '\n';
  }
  // std::cerr << ans << '\n';
  // return;

  while (!s.empty()) s.pop();
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] <= a[i]) {
      s.pop();
    }
    l[i] = (s.empty() ? 0 : s.top()) + 1;
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] < a[i]) {
      s.pop();
    }
    r[i] = (s.empty() ? n + 1 : s.top()) - 1;
    s.push(i);
  }
  for (int i = 1; i <= n; i++) {
    ans += (r[i] - i + 1) * (i - l[i] + 1) * a[i];
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