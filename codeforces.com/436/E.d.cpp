#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int N = 3e5, M = 3e5, MX = 1e9;
  int n = N, m = M;
  if (argc > 1) n = atoi(argv[1]);
  if (argc > 2) m = atoi(argv[2]);
  if (argc > 3) MX = atoi(argv[3]);

  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    int b = rd() % MX + 1;
    std::cout << rd() % (b - 1) + 1 << ' ' << b << '\n';
  }

  return 0;
}