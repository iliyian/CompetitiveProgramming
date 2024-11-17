#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k, w;
  std::cin >> n >> m >> k >> w;
  std::vector<int> r(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> r[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  std::sort(r.begin() + 1, r.end());
  std::sort(b.begin() + 1, b.end());
  std::vector<int> ans;
  int prv = 1;
  bool f = false;
  auto solve = [&](int s, int t, int L, int R) {
    if (s > t) return;
    std::vector<int> cur;
    // std::cout << s << ' ' << t << ' ' << L << ' ' << R << '\n';

    for (int i = s; i <= t;) {
      cur.push_back(r[i]);
      i = std::upper_bound(r.begin() + i, r.begin() + t + 1, r[i] + k - 1) - r.begin();
    }
    for (int i = cur.size() - 1; i >= 0; i--) {
      if (cur[i] + k - 1 >= R || i != cur.size() - 1 && cur[i] + k - 1 >= cur[i + 1]) {
        cur[i] = (i == cur.size() - 1 ? R : cur[i + 1]) - k;
      }
    }
    if (cur[0] <= L) {
      f = true;
      return;
    }
    for (auto p : cur) {
      // std::cout << p << ' ';
      ans.push_back(p);
    }
    // std::cout << '\n';
  };
  b[0] = 0;
  // b[m + 1] = w;
  for (int i = 1; i <= m; i++) {
    int x = std::lower_bound(r.begin() + prv, r.end(), b[i]) - r.begin() - 1;
    std::vector<int> cur;
    // std::cout << prv << ' ' << x << '\n';
    solve(prv, x, b[i - 1], b[i]);
    prv = x + 1;
  }
  solve(prv, n, b[m], w + 1);
  if (f) {
    std::cout << -1 << '\n';
    return;
  }

  std::cout << ans.size() << '\n';
  for (auto p : ans) {
    std::cout << p << ' ';
  }
  std::cout << '\n';
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