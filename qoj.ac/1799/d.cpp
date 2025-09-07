#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 5e5, m = 5e5, w = 1e9, k = 1e7;
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % w + 1 << ' ';
  }
  std::cout << '\n';
  while (m--) {
    int op = rd() % 4 + 1;
    if (op == 1 || op == 2) {
      int x = rd() % n + 1, kk = rd() % k + 1;
      std::cout << op << ' ' << x << ' ' << kk << '\n';
    } else {
      int x = rd() % n + 1;
      std::cout << op << ' ' << x << '\n';
    }
  }

  return 0;
}