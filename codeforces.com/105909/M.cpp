#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
  }
  int rkg, rks, rkb, pg, ps, pb;
  std::cin >> rkg >> rks >> rkb >> pg >> ps >> pb;
  rkg--, rks--, rkb--;
  for (int S = 0; S < (1 << n); S++) {
    if (__builtin_popcountll(S) > 13 || __builtin_popcountll(S) < 10) continue;
    std::vector<int> b;
    for (int i = 1; i <= m; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        cnt += (a[i][j] - '0') && (S >> j & 1);
      }
      b.push_back(cnt);
    }
    std::sort(b.begin(), b.end(), std::greater<>());
    if (b[rkg] == pg && b[rks] == ps && b[rkb] == pb) {
      std::cout << __builtin_popcountll(S) << '\n';
      for (int i = 0; i < n; i++) {
        if (S >> i & 1) {
          std::cout << i + 1 << ' ';
        }
      }
      std::cout << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}