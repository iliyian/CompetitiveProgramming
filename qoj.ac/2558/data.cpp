#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  std::ofstream os("d.in");

  int t = 1;
  os << t << '\n';
  while (t--) {
    int n = 11111, q = 11000, w = 1000;
    os << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) {
      os << rd() % w + 1 << ' ';
    }
    os << '\n';
    for (int i = 2; i <= n; i += 2) {
      int p = rd() % (i - 1) + 1;
      os << p << ' ' << i << '\n';
      os << p << ' ' << i + 1 << '\n';
    }
    os << '\n';
    while (q--) {
      int x = rd() % n + 1, y = rd() % n + 1;
      while (x == y) {
        x = rd() % n + 1, y = rd() % n + 1;
      }
      os << x << ' ' << y << '\n';
    }
  }

  return 0;
}