#include <bits/stdc++.h>
#define int long long

struct Node {
  int w, v;
  bool operator < (const Node &b) const {
    return w > b.w;
  }
};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<Node> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].w >> a[i].v;
  }
  std::sort(a.begin() + 1, a.end());
  std::multiset<int> s;
  std::vector<std::vector<int>> f(n + 2, std::vector<int>(m + 1, INT_MIN));
  f[n + 1][0] = 0;
  for (int i = n; i >= 1; i--) {
    std::copy(f[i + 1].begin(), f[i + 1].end(), f[i].begin());
    for (int j = m; j >= a[i].w; j--) {
      f[i][j] = std::max(f[i][j], f[i][j - a[i].w] + a[i].v);
    }
  }
  int ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    if (i) {
      s.insert(a[i].v);
      sum += a[i].v;
    }
    if (s.size() > k) {
      sum -= *s.begin();
      s.erase(s.begin());
    }
    ans = std::max(ans, sum + *std::max_element(f[i + 1].begin(), f[i + 1].end()));
    // std::cout << ans << '\n';
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}