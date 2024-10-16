#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::priority_queue<int> q;
  q.push(a.back());
  for (int i = n - 1; i >= 1; i--) {
    a[i] += a[i + 1];
    if (i != 1) {
      q.push(a[i]);
    }
  }
  int ans = a[1];
  for (int i = 2; i <= n; i++) {
    std::cout << ans << ' ';
    ans += q.top(); q.pop();
  }
  std::cout << ans << '\n';
  return;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("F.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}