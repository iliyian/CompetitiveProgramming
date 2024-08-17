#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int w;
  std::cin >> w;
  std::vector<int> a(w + 1);
  for (int i = 1; i <= w; i++) {
    std::cin >> a[i];
  }
  std::vector<int> p;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int r = std::min({i, n - i + 1, n - k + 1, k}), c = std::min({m - k + 1, j, m - j + 1, k});
      p.push_back(r * c);
    }
  }
  std::sort(p.begin(), p.end(), std::greater());
  std::sort(a.begin() + 1, a.end(), std::greater());
  int ans = 0;
  for (int i = 1; i <= w; i++) {
    ans += a[i] * p[i - 1];
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}