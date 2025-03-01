#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#define int long long

struct Node {
  int l, r;
  bool operator < (const Node &b) const {
    return std::tie(r, l) < std::tie(b.r, b.l);
  }
};

void solve() {
  int n, m, L, V;
  std::cin >> n >> m >> L >> V;
  std::vector<int> need(n + 1);
  std::vector<int> d(n + 1), v(n + 1), a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> d[i] >> v[i] >> a[i];
  }
  std::vector<double> p(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> p[i];
  }
  std::vector<Node> needs;
  auto add = [&](int l, int r) {
    if (l <= r && l >= 1 && r <= m) {
      needs.push_back({l, r});
    }
  };
  for (int i = 1; i <= n; i++) {
    if (a[i] > 0) {
      if (v[i] <= V) {
        double tn = double(V - v[i]) / a[i];
        double x = v[i] * tn + 0.5 * a[i] * tn * tn + d[i];
        int l = std::upper_bound(p.begin() + 1, p.end(), x) - p.begin();
        add(l, m);
      } else {
        int l = std::lower_bound(p.begin() + 1, p.end(), d[i]) - p.begin();
        add(l, m);
      }
    } else if (a[i] < 0) {
      if (v[i] > V) {
        double tn = double(V - v[i]) / a[i];
        double x = v[i] * tn + 0.5 * a[i] * tn * tn + d[i];
        int r = std::lower_bound(p.begin() + 1, p.end(), x) - p.begin() - 1;
        int l = std::lower_bound(p.begin() + 1, p.end(), d[i]) - p.begin();
        add(l, r);
      }
    } else {
      if (v[i] > V) {
        add(std::lower_bound(p.begin() + 1, p.end(), d[i]) - p.begin(), m);
      }
    }
  }
  std::sort(needs.begin(), needs.end());
  int now = 0, ans = 0;
  std::vector<int> placed;
  for (auto [l, r] : needs) {
    auto x = std::lower_bound(placed.begin(), placed.end(), l) - placed.begin();
    if (x == placed.size()) {
      placed.push_back(r);
    }
  }
  std::cout << needs.size() << ' ' << m - placed.size() << '\n';
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