#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int N = 1e5;
  int n = 1e5;
  if (argc > 1) n = atoi(argv[1]);
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    // std::cout << std::uniform_int_distribution<int>{1, N}(rd) << ' ';
    std::cout << (i & 1 ? 1 : N) << ' ';
  }
  std::cout << '\n';

  return 0;
}