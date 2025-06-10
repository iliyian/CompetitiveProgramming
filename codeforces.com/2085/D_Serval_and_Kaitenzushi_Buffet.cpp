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
  int ans = 0;
  for (int i = n - k; i >= 1; i--) {
    if ((q.size() + 1) * (k + 1) <= n - i + 1) {
      q.push(a[i]);
      ans += a[i];
    } else {
      if (q.top() <= a[i]) {
        ans -= q.top();
        q.pop();
        ans += a[i];
        q.push(a[i]);
      }
    }
  }
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