// date: 2024-10-04 21:58:52
// tag: 树状数组维护区间颜色数

#include <bits/stdc++.h>

constexpr int N = 1e6;

std::vector<int> d(N + 1);

void add(int x, int c) {
  for (int i = x; i <= N; i += i & -i) d[i] += c;
}

int query(int x) {
  int ans = 0;
  for (int i = x; i > 0; i -= i & -i) ans += d[i];
  return ans;
}

void solve() {
  int n, m;
  std::cin >> n;
  std::vector<int> a(n + 1), prv(N + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<std::pair<int, int>>> p(n + 1);
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int l, r;
    std::cin >> l >> r;
    p[r].push_back({l, i});
  }
  std::vector<int> ans(m + 1);
  for (int i = 1; i <= n; i++) {
    if (prv[a[i]]) {
      add(prv[a[i]], -1);
    }
    prv[a[i]] = i;
    add(i, 1);
    for (auto &[l, idx] : p[i]) {
      ans[idx] = query(i) - query(l - 1);
    }
  }
  for (int i = 1; i <= m; i++) {
    std::cout << ans[i] << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("main.in", "r", stdin);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}