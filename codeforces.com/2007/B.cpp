#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int mx = *std::max_element(a.begin() + 1, a.end());
  for (int i = 1; i <= m; i++) {
    char op;
    int x, y;
    std::cin >> op >> x >> y;
    if (mx >= x && mx <= y) {
      mx += (op == '+' ? 1 : -1);
    }
    std::cout << mx << ' ';
  }
  std::cout << '\n';
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