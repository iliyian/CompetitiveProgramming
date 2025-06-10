#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 5e5, q = 5e5;
  std::cout << n << ' ' << q << '\n';
  for (int i = 2; i <= n; i++) {
    std::cout << rd() % (i - 1) + 1 << ' ' << i << '\n';
    // std::cout << i - 1 << ' ' << i << '\n';
  }
  while (q--) {
    int op = (std::uniform_real_distribution<>{0.0, 1.0}(rd) <= 0.4) + 1;
    std::cout << op << ' ';
    if (op == 1) {
      std::cout << rd() % n + 1 << ' ' << rd() % (int)1e6 + 1 << '\n';
    } else {
      std::cout << rd() % n + 1 << '\n';
    }
  }

  return 0;
}