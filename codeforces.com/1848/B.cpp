#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> col(k + 1);
  for (auto &v : col) {
    v.push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    col[x].push_back(i);
  }
  for (auto &v : col) {
    v.push_back(n + 1);
  }
  int ans = LLONG_MAX;
  for (auto &v : col) {
    int m1 = 0, m2 = 0;
    for (int i = 1; i < v.size(); i++) {
      int d = v[i] - v[i - 1] - 1;
      if (d > m1) {
        m2 = m1, m1 = d;
      } else if (d > m2) {
        m2 = d;
      }
    }
    ans = std::min(ans, std::max(m1 / 2, m2));
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}