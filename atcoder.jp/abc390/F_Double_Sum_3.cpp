// date: 2025-02-12 21:56:13
// tag: 类似abc371e的根据某个值首次出现的位置划分区间，计算贡献的题

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pre(n + 1), nxt(n + 1, n + 1), pos(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = std::max(pos[a[i]], pos[a[i] + 1]);
    pos[a[i]] = i;
  }
  std::fill(pos.begin(), pos.end(), n + 1);
  for (int i = n; i >= 1; i--) {
    nxt[i] = std::min(nxt[i], pos[a[i] + 1]);
    pos[a[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (i - pre[i]) * (nxt[i] - i);
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