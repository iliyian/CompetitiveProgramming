#include <bits/stdc++.h>
#define int long long

std::ifstream din("d.in"), dout("d.out");

bool f = true;

void solve() {
  int n;
  din >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    din >> a[i].first >> a[i].second;
  }
  auto dot = [&](int i, int j, int k) {
    return (a[k].first - a[i].first) * (a[j].first - a[i].first) + (a[k].second - a[i].second) * (a[j].second - a[i].second);
  };
  int ans = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        ans = std::min(ans, dot(i, j, k));
      }
    }
  }
  int got;
  dout >> got;
  if (got != ans) {
    std::cout << "WRONG ANSWER\n";
    std::cout << ans << ' ' << got << '\n';
    std::ofstream os("-1.in");
    std::cout << 1 << '\n';
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << a[i].first << ' ' << a[i].second << '\n';
    }
    std::cout << '\n';
    exit(0);
  } else {
    std::cout << "ACCEPTED\n";
    std::cout << ans << ' ' << got << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  din >> t;

  while (t--) {
    solve();
  }

  return 0;
}