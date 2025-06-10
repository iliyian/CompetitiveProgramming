// date: 2025-04-03 20:27:08
// tag: 

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::priority_queue<int, std::vector<int>, std::greater<>> q;
  int sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (q.size() == k - 1) {
      ans = std::max(ans, sum + a[i] + i);
    }
    q.push(a[i]);
    sum += a[i];
    if (q.size() == k) {
      sum -= q.top(); q.pop();
    }
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