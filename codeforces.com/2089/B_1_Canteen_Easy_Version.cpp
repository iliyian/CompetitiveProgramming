// date: 2025-04-13 22:03:56
// tag: 主打一个写难写的，明明可以st表加二分但她非要单调栈。这题主要是推性质。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n * 2 + 1), b(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    b[i + n] = b[i];
  }
  for (int i = 1; i <= n * 2; i++) {
    a[i] += a[i - 1];
    b[i] += b[i - 1];
  }
  std::stack<int> s;
  int ans = 0;
  std::vector<int> r(n * 2 + 1);
  for (int i = 1; i <= n * 2; i++) {
    s.push(i - 1);
    while (!s.empty() && a[s.top()] - b[s.top()] >= a[i] - b[i]) {
      // r[s.top() + 1] = i;
      // std::cerr << i << ' ' << s.top() << '\n';
      ans = std::max(ans, i - s.top());
      s.pop();
    }
  }
  // for (int i = 1; i <= n * 2; i++) {
    // std::cout << r[i] << " \n"[i == n * 2];
  // }
  std::cout << ans << '\n';
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