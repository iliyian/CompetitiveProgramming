#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("gg.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 20;
  std::cout << t << '\n';
  while (t--) {
    int n = 1e5;
    std::cout << n << ' ' << rd() % (n * (n + 1) / 2) + 1 << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % (int)(1e9) << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}