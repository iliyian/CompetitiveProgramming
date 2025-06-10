#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("dd.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 10;
  std::cout << t << '\n';
  while (t--) {
    int n = 5, m = 5;
    std::cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        std::cout << rd() % 1000 + 1 << ' ';
      }
      std::cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        std::cout << rd() % 1000 + 1 << ' ';
      }
      std::cout << '\n';
    }
  }

  return 0;
}