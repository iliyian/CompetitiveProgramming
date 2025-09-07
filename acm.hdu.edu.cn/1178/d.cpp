#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // freopen("d.in", "w", stdout);

  std::mt19937_64 rd(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = 10, k = rd() % n + 1, w = 1;
    std::cout << n << ' ' << k << '\n';
    for (int i = 1; i <= n; i++) {
      int a = rd() % w + 1, b = rd() % (a / 2 + 1);
      std::cout << a << ' ' << b << '\n';
      // std::cout << w << ' ' << w - 1 << '\n';
    }
  }

  return 0;
}