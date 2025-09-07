#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 100;
  std::cout << t << '\n';
  while (t--) {
    int n = 100, m = 200, w = 200000;
    std::cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % w + 1 << ' ';
    }
    std::cout << '\n';
    for (int i = 2; i <= n; i++) {
      std::cout << i << ' ' << rd() % (i - 1) + 1 << '\n';
    }
    while (m--) {
      int op = rd() % 2 + 1;
      std::cout << op << ' ';
      if (op == 1) {
        int x = rd() % n + 1, y = rd() % n + 1;
        std::cout << x << ' ' << y << '\n';
      } else {
        int x = rd() % n + 1, y = rd() % w + 1;
        std::cout << x << ' ' << y << '\n';
      }
    }
  }

  return 0;
}