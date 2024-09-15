#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<int> b(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  std::sort(b.begin() + 1, b.end());
  while (q--) {
    int a;
    std::cin >> a;
    auto y = std::lower_bound(b.begin() + 1, b.end(), a);
    if (y == b.end()) {
      std::cout << n - b.back() << '\n';
      continue;
    }
    if (std::prev(y) == b.begin()) {
      std::cout << b[1] - 1 << '\n';
      continue;
    }
    auto x = std::prev(y);
    std::cout << (*y - *x) / 2 << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B2.in", "r", stdin);
  freopen("B2.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}