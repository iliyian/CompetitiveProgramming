#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = 400, m = 400, q = 3e5;
    std::cout << n << ' ' << m << ' ' << q << '\n';
    for (int i = 1; i <= m; i++) {
      int x = rd() % n + 1, y = rd() % n + 1;
      while (x == y) {
        x = rd() % n + 1, y = rd() % n + 1;
      }
      std::cout << x << ' ' << y << ' ' << rd() % (int)1e9 + 1 << '\n';
    }
    while (q--) {
      int x = rd() % n + 1, y = rd() % n + 1;
      while (x == y) {
        x = rd() % n + 1, y = rd() % n + 1;
      }
      std::cout << x << ' ' << y << ' ' << rd() % m + 1 << '\n';
    }
  }

  return 0;
}