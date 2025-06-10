#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 2000, m = 2000, w = 10;
  std::cout << n << ' ' << m << '\n';
  std::set<std::pair<int, int>> s;
  for (int i = 1; i <= m; i++) {
    int x, y;
    do {
      x = rd() % n + 1;
      y = x;
      int t = rd() % 2 + 1;
      for (int j = 0; j < t; j++) {
        y <<= 1;
        y += rd() % 2;
      }
    }
    while (x > n || y > n || x == y || s.count({x, y}));
    s.insert({x, y});
    std::cout << x << ' ' << y << ' ' << rd() % w + 1 << '\n';
  }
  int q = 1;
  std::cout << q << '\n';
  while (q--) {
    int x = rd() % n + 1, y = rd() % n + 1;
    std::cout << x << ' ' << y << '\n';
  }

  return 0;
}