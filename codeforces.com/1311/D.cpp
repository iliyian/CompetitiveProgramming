// date: 2024-08-03 13:10:53
// tag: 暴力

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 2e4;

std::vector<std::vector<int>> fac(N + 1);

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  int ans = INT_MAX;
  int ax, ay, az;
  auto chm = [&](int x, int y, int z) {
    if (ans > std::abs(a - x) + std::abs(b - y) + std::abs(c - z)) {
      ans = std::abs(a - x) + std::abs(b - y) + std::abs(c - z);
      return true;
    }
    return false;
  };
  for (int z = 1; z <= N; z++) {
    for (int y : fac[z]) {
      for (int x : fac[y]) {
        if (chm(x, y, z)) {
          ax = x, ay = y, az = z;
        }
      }
    }
  }
  std::cout << ans << '\n';
  std::cout << ax << ' ' << ay << ' ' << az << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
} 