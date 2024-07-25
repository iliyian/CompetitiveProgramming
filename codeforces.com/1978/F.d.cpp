#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int N = 1e6, K = 2e6;
  int k = 10;
  int t = 1;
  int n = N / t;
  std::cout << t << '\n';
  while (t--) {
    std::cout << n << ' ' << k << '\n';
    for (int i = 0; i < n; i++) {
      std::cout << std::uniform_int_distribution<int>{1, N}(rd) << ' ';
      // std::cout << 1 << ' '
    }
    std::cout << '\n';
  }

  return 0;
}