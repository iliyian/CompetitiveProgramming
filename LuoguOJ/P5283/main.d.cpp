#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int N = 5e5, K = 2e5, lim = (1ll << 32) - 1;

  int n = N, k = K;
  std::cout << n << ' ' << k << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << std::uniform_int_distribution<int>{0, lim}(rd) << ' ';
  }

  return 0;
}