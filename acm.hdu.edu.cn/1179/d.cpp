#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = 2e3, q = 2e3;
    std::cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % n + 1 << ' ';
    }
    std::cout << '\n';
    while (q--) {
      int x = rd() % n + 1, v = rd() % n + 1;
      std::cout << x << ' ' << v << '\n';
    }
  }

  return 0;
}