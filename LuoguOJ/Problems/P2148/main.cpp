// date: 2024-08-16 14:30:55
// tag: sg函数，博弈论

#include <bits/stdc++.h>
#define int long long
// using namespace std;

// constexpr int N = 32;

// std::vector<std::vector<int>> sg(N + 1, std::vector<int>(N + 1, -1));

int calc(int x, int y) {
  if (x == 1 && y == 1) return 0;
  if (x % 2 && y % 2) return 0;
  return calc((x + 1) / 2, (y + 1) / 2) + 1;
}

void solve() {
  int n;
  std::cin >> n;
  int x = 0;
  for (int i = 1; i <= n; i += 2) {
    int a, b;
    std::cin >> a >> b;
    x ^= calc(a, b);
  }
  std::cout << (x ? "YES" : "NO") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  // auto calc = [&](auto self, int x, int y) -> int {
  //   if (x == 1 && y == 1) return 0;
  //   if (x < y) std::swap(x, y);
  //   if (sg[x][y] != -1) return sg[x][y];
  //   std::set<int> s;
  //   for (int i = 1; i < x; i++) {
  //     s.insert(self(self, i, x - i));
  //   }
  //   for (int i = 1; i < y; i++) {
  //     s.insert(self(self, i, y - i));
  //   }
  //   sg[x][y] = 0;
  //   while (s.contains(sg[x][y])) {
  //     sg[x][y]++;
  //   }
  //   return sg[x][y];
  // };

  // for (int i = 1; i <= N; i++) {
  //   // std::cout << i << ": ";
  //   for (int j = 1; j <= N; j++) {
  //     std::cout << calc(calc, i, j) << ' ';
  //   }
  //   std::cout << '\n';
  // }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}