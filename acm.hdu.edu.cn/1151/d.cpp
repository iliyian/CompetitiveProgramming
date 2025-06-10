#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 20;
  int t = (n + 1) * (n + 1) - 1;
  std::cout << t << '\n';
  for (int r = 0; r <= n; r++) {
    for (int b = 0; b <= n; b++) {
      // for (int m = 0; m <= n; m++) {
        // if (!r && !b && !m) continue;
        if (!r && !b) continue;
        std::cout << r << ' ' << b << ' ' << 0 << '\n';
      // }
    }
    // int r = rd() % 20, b = rd() % 20, m = rd() % 20;
    // while (r == 0 && b == 0 && m == 0) {
    //   r = rd() % 10, b = rd() % 10, m = rd() % 10;
    // }
    // std::cout << r << ' ' << b << ' ' << m << ' ';
    // std::cout << '\n';
  }

  return 0;
}