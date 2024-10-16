// date: 2024-10-06 14:40:42
// tag: 颜色统计，mex

#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

std::vector<int> pos(N + 1), d(N + 1);

void add(int x, int c) {
  for (int i = x; i <= N; i += i & -i) d[i] += c;
}

int query(int x) {
  int ans = 0;
  for (int i = x; i > 0; i -= i & -i) ans += d[i];
  return ans;
}

int mex(const std::set<int> &x) {
  for (int i = 1;; i++) {
    if (!x.count(i)) {
      return i;
    }
  }
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  std::vector<std::vector<std::array<int, 2>>> p(n + 1);
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (pos[a[i]] < i - 1) {
      p[i - 1].push_back({pos[a[i]] + 1, a[i]});
    }
    pos[a[i]] = i;
    s.insert(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (pos[a[i]]) {
      if (pos[a[i]] < n) {
        p[n].push_back({pos[a[i]] + 1, a[i]});
      }
      pos[a[i]] = 0;
    }
  }
  int ans = INT_MIN;
  for (int i = 1; i <= n; i++) {
    if (pos[a[i]]) {
      add(pos[a[i]], -1);
    }
    pos[a[i]] = i;
    add(i, 1);
    for (auto &[l, x] : p[i]) {
      ans = std::max(ans, query(i) - query(l - 1) - x);
    }
    if (i == n) {
      ans = std::max(ans, (int)s.size() - mex(s));
    }
  }
  std::cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    if (pos[a[i]]) {
      add(pos[a[i]], -1);
      pos[a[i]] = 0;
    }
  }
}

signed main() {
  freopen("I.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}