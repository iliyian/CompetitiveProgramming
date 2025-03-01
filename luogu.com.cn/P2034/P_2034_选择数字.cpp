// date: 2025-03-01 15:16:19
// tag: 单调队列优化dp+正难则反

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), f(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  std::deque<int> q;
  q.push_back(0);
  for (int i = 1; i <= n; i++) {
    while (!q.empty() && q.front() < i - k - 1) q.pop_front();
    f[i] = f[q.front()] + a[i];
    while (!q.empty() && f[q.back()] >= f[i]) q.pop_back();
    q.push_back(i);
    // std::cerr << f[i] << ' ';
  }
  // std::cerr << '\n';
  int ans = sum;
  for (int i = n - k; i <= n; i++) {
    ans = std::min(ans, f[i]);
  }
  std::cout << sum - ans << '\n';
  // std::cout << f[n] << '\n';
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