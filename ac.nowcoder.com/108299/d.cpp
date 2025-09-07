#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = 5000, m = 100000;
    std::cout << n << ' ' << m << '\n';
    for (int i = 1; i <= m; i++) {
      int x = rd() % n + 1, y = rd() % n + 1, t = rd() % (int)1e3 + 1, w = rd() % 10 + 1;
      std::cout << x << ' ' << y << ' ' << t << ' ' << w << '\n';
    }
    int q = 50;
    std::cout << q << '\n';
    while (q--) {
      int k = rd() % (int)10 + 1;
      std::cout << k << '\n';
    }
  }

  return 0;
}