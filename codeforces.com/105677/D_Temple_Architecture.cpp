#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::stack<int> s;
  std::vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] <= a[i]) {
      s.pop();
    }
    l[i] = (s.empty() ? 0 : s.top());
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] <= a[i]) {
      s.pop();
    }
    r[i] = (s.empty() ? 0 : s.top());
    s.push(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!l[i] && !r[i]) continue;
    else if (!l[i]) ans += r[i] - i;
    else if (!r[i]) ans += i - l[i];
    else ans += std::min(r[i] - i, i - l[i]);
    // std::cerr << l[i] << ' ' << r[i] << '\n';
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