#include <bits/stdc++.h>
#define int long long
// using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int sx, sy;
  std::cin >> sx >> sy;
  bool f = false;
  for (int i = 1; i <= k; i++) {
    int x, y;
    std::cin >> x >> y;
    if ((std::abs(x - sx) + std::abs(y - sy)) % 2 == 0) {
      f = true;
    }
  }
  std::cout << (f ? "NO" : "YES") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}