#include <bits/stdc++.h>
#include <random>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 10, q = 2e6;
  std::cout << n << ' ' << q << '\n';
  for (int i = 1; i <= n; i++) {
    int m = rd() % (int)1e5 + 1;
    std::cout << m << '\n';
    for (int j = 1; j <= m; j++) {
      std::cout << rd() % 400 + 1 << ' ' << rd() % 400 + 1 << ' ' << rd() % 400 + 1 << '\n';
    }
  }
  std::cout << std::uniform_int_distribution<>{(int)1e8, (1ll << 31) - 1}(rd) << '\n';

  return 0;
}