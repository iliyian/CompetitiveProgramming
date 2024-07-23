// date: 2024-07-23 09:25:53

// date: 2024-07-23 09:15:48
// tag: 数学，暴力

#include <bits/stdc++.h>
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1);
  std::vector<int> x(n + 1), y(n + 1);
  std::vector<int> buc(n + 1);
  int64_t ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
    int g = std::gcd(p[i], i);
    x[i] = i / g, y[i] = p[i] / g;
    if (y[i] % x[i] == 0) {
      ans--;
    }
  }
  std::vector<std::vector<int>> bucx(n + 1), bucy(n + 1);
  for (int i = 1; i <= n; i++) {
    bucx[x[i]].push_back(y[i]);
    bucy[y[i]].push_back(x[i]);
  }
  
  std::vector<std::vector<int>> fac(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      fac[j].push_back(i);
    }
  }
  for (int xi = 1; xi <= n; xi++) {
    for (int yj = xi; yj <= n; yj += xi) {
      for (int s : bucy[yj]) {
        buc[s]++;
      }
    }
    for (int yi : bucx[xi]) {
      for (auto s : fac[yi]) {
        ans += buc[s];
      }
    }
    for (int yj = xi; yj <= n; yj += xi) {
      for (int s : bucy[yj]) {
        buc[s]--;
      }
    }
  }

  std::cout << ans / 2 << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G1.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}