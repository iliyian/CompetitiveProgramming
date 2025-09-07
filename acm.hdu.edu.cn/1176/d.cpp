#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = 5, q = 5, w = 10;
    std::cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % w + 1 << " \n"[i == n];
    }
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % w + 1 << " \n"[i == n];
    }
    for (int i = 2; i <= n; i++) {
      std::cout << rd() % (i - 1) + 1 << ' ' << i << '\n';
    }
    for (int i = 1; i <= q; i++) {
      int x = rd() % n + 1, y = rd() % w + 1;
      std::cout << x << ' ' << y << '\n';
    }
  }

  return 0;
}