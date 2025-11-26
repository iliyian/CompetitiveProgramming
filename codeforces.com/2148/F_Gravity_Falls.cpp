#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1);
  int mxk = 0;
  std::vector<int> k(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> k[i];
    mxk = std::max(mxk, k[i]);
    a[i].push_back(0);
    for (int j = 1; j <= k[i]; j++) {
      int x;
      std::cin >> x;
      a[i].push_back(x);
    }
  }
  int w = 1;
  std::multiset<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  auto cmp = [&](auto x, auto y) {
    for (int i = w; i <= std::min(k[x], k[y]); i++) {
      if (a[x][i] != a[y][i]) {
        return a[x][i] < a[y][i];
      }
    }
    return k[x] < k[y];
  };
  while (w <= mxk) {
    int x = *s.begin();
    for (auto y : s) {
      if (cmp(y, x)) {
        x = y;
      }
    }
    for (int i = w; i <= k[x]; i++) {
      std::cout << a[x][i] << ' ';
    }
    w = k[x] + 1;
    std::erase_if(s, [&](auto x) {
      return k[x] < w;
    });
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}