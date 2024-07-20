#include <bits/stdc++.h>
#include <random>
#define int long long
// using namespace std;

signed main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "w", stdout);

  std::mt19937_64 rd(std::random_device{}());

  int W = 1e9, N = 1e5;
  int t = 1, n = N / t;

  std::cout << t << '\n';
  while (t--) {
    std::cout << n << '\n';
    int i;
    for (i = 0; i < n / 2; i++) {
      std::cout << std::uniform_int_distribution<int>{1, W}(rd) << ' ';
    }
    for (; i < n; i++) {
      std::cout << std::uniform_int_distribution<int>{1, 1000}(rd) << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}