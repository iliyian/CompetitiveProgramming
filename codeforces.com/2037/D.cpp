// date: 2024-11-29 17:51:32
// tag: 边界情况别搞错了，及记得足够贪心，记得pq

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, L;
  std::cin >> n >> m >> L;
  std::vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
  }
  std::vector<int> x(m + 1), v(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> x[i] >> v[i];
  }
  int ans = 0, k = 1, pos = 1;
  std::priority_queue<int> q;
  for (int i = 1; i <= n; i++) {
    while (pos <= m && x[pos] < l[i]) {
      q.push(v[pos++]);
    }
    while (!q.empty() && k <= r[i] - l[i] + 1) {
      k += q.top(); q.pop();
      ans++;
    }
    if (k <= r[i] - l[i] + 1) {
      std::cout << -1 << '\n';
      return;
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}